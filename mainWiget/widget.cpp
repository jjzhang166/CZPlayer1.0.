#include "stdafx.h"
#include "widget.h"
#include "static.h"
#include "czplayerconfig.h"
#include "ClientBaseOperating.h"
#include "DBModule.h"

/*

增加数据库功能
                                                         -> 把音乐信息录入数据库(必须把音乐路径录入)
1.运行程序 -> 打开音乐文件 -> 把全部音乐文件加载到媒体源
                                                         -> 把音乐信息显示到音乐表格

                                       -> 把音乐文件显示到音乐表格
2.运行程序 -> 把音乐文件从数据库中读出
                                       -> 根据音乐文件路径查找音乐 -> 把音乐文件加载到媒体源

*/

/*
CTRL_CLOSE_EVENT, CTRL_LOGOFF_EVENT和CTRL_SHUTDOWN_EVENT通常被用来处理一些程序的清理工作，
然后调用ExitProcess API。另外，这三个事件有超时机制，CTRL_CLOSE_EVENT是5秒，另外两个是20秒。
如果程序超时候，系统将会弹出结束进程的对话框。如果用户选择了结束进程，
任何清理工作都不会做，所以应该在超时时间内完成工作
*/
//事件处理回调
BOOL HandlerRoutine(DWORD dwCtrlType)  
{  
	switch (dwCtrlType)  
	{  
	case CTRL_C_EVENT:						//Ctrl+C，系统会发送次消息
		qDebug() << "ctrl+c--程序不会关闭";
		return TRUE;  
	case CTRL_CLOSE_EVENT:					 //当用户关闭Console时，系统会发送次消息
		qDebug() << "ctrl close--正常关闭";
		return TRUE;  
	case CTRL_BREAK_EVENT:					//Ctrl+break，系统会发送次消息
		qDebug() << "CTRL_BREAK_EVENT";  
		return TRUE;
	case CTRL_LOGOFF_EVENT:					//用户退出（注销），系统会发送次消息
		qDebug() << "CTRL_LOGOFF_EVENT--用户退出或注销";  
		return TRUE;
	case CTRL_SHUTDOWN_EVENT:				//系统关闭，系统会发送次消息
		qDebug() << "CTRL_SHUTDOWN_EVENT--系统关闭";  
		return TRUE;
	default: 
		return FALSE;  
	}  
} 

//构造函数
Widget::Widget()
{
	//安装事件处理
	if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, TRUE))
	{
		qDebug() << "安装事件处理失败！";
	}

	//step = 0;
	//baseTimer.start(60, this);

	ClientBaseOperating::touchConfigFile();//创建一个配置文件
	readyReadDb = 0;//没有从数据库中读取
	DBModule::initDB();//初始化数据库
	ClientBaseOperating::mkdirDownloadDir();//创建一个下载歌曲目录
	ClientBaseOperating::mkdirAlbumDir();//创建一个文件夹来存储下载的专辑
	ClientBaseOperating::mkdirLrcDir();//创建一个下载歌词目录

    //设置窗口基本属性
    this ->resize(400, 212);//设置窗体大小
    this ->setWindowFlags(Qt::FramelessWindowHint);//去掉窗体边框
    this ->setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
    this ->setWindowIcon(QIcon(":/images/CZPlayer.png"));//设置logo
    this ->setAcceptDrops(true);//可以拖放文件
    this ->setWindowTitle(tr("CZPlayer"));

    //    qDebug() << "电脑屏幕大小：" << QApplication::desktop() ->width() << ", " << QApplication::desktop() ->height();
    //    qDebug() << "鼠标当前位置：" << QCursor::pos();
    //    qDebug() << "软件界面大小：" << this ->frameGeometry();
    //    qDebug() << "软件界面相对于屏幕的绝对坐标：" << this ->mapToParent(QPoint(0, 0));
    //    qDebug() << "软件界面相对于屏幕的绝对坐标：" << this ->pos();
    //    qDebug() << frameGeometry().topRight();

    //设置界面渐变显示
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation ->setDuration(1000);
    animation ->setStartValue(0);
    animation ->setEndValue(1);
    animation ->start();

    //创建媒体对象
    mediaObject = new Phonon::MediaObject(this);
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(mediaObject, audioOutput);//绑定源和接收器

    //创建控制播放进度的滑块
    seekSlider = new Phonon::SeekSlider(mediaObject, this);
    seekSlider ->setStyleSheet("QSlider::groove:horizontal:!hover{border-image: url(:/images/progressBar.png);}"
                               "QSlider::groove:horizontal:hover{border-image: url(:/images/progressBar2.png);}"
                               //"QSlider::add-page{border-image: url(:/images/jd.png);}"
                               "QSlider::sub-page{border-image: url(:/images/progressBarSub.png);}");
    //    seekSlider->setStyleSheet("QSlider::groove:horizontal:!hover{border-image: url(:/images/progressBar.png);}"
    //                              "QSlider::groove:horizontal:hover{border-image: url(:/images/progressBar2.png);}");
    //                              "QSlider::sub-page{background:green; border-radius:7px; height:7}");
    //                              "QSlider::add-page{background:pink;}");
    seekSlider ->setObjectName(tr("seekSlider"));

    //创建音量调节滑块
    volumeSlider = new Phonon::VolumeSlider(audioOutput, this);
    volumeSlider ->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    volumeSlider ->setStyleSheet("QSlider::groove:horizontal:!hover{border-image: url(:/images/volumeBar.png);}"
                                 "QSlider::groove:horizontal:hover{border-image: url(:/images/volumeBar2.png);}"
                                 //"QSlider::add-page{border-image: url(:/images/jd.png);}"
                                 "QSlider::sub-page{border-image: url(:/images/volumeBarSub.png);}");
    volumeSlider ->setObjectName(tr("volumeSlider"));

    //专辑封面
    albumImage = new QLabel(this);
    albumImage ->setToolTip(tr("专辑封面"));
    albumImage ->setPixmap(QPixmap(tr(":/images/albumImage.png")));
    movie = new QMovie(tr(":/images/jiaZai.gif"));
//    albumImage ->setMovie(movie);
//    movie ->start();

    //信息显示标签
    InfoLabel = new QLabel(this);
    InfoLabel ->setObjectName("InfoLabel");
    InfoLabel ->setText(tr("Welecome to CZPlayer!"));

    //歌词标签
	lrcLabel = new QLabel(this);
	lrcLabel ->setObjectName(tr("lrcLabel"));
	lrcLabel ->setText(tr("highway-9"));

    //设置显示时间标签
    timeLabel = new QLabel(tr("00:00/00:00"), this);
    timeLabel ->setToolTip(tr("当前时间/总时间"));
    timeLabel ->setObjectName(tr("timeLabel"));
    timeLabel ->setAlignment(Qt::AlignCenter);//设置对齐格式
    //QSizePolicy类是描述水平和垂直修改大小策略的一种属性
    timeLabel ->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);//水平方向上尺寸可扩展，竖直方向已固定

    //显示下载页面
    showButton = new QPushButton(this);
    showButton ->setObjectName(tr("showButton"));
    showButton ->setToolTip(tr("打开下载列表"));
    showButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/showButton.png);}"
                               "QPushButton:hover{border-image: url(:/images/showButton2.png);}"
                               "QPushButton:pressed{border-image: url(:/images/showButton3.png);}");

    //播放
    playButton = new QPushButton(this);
    playButton ->setToolTip(tr("播放"));
    playButton ->setObjectName(tr("playButton"));
    playButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/playButton.png);}"
                               "QPushButton:hover{border-image: url(:/images/playButton2.png);}"
                               "QPushButton:pressed{border-image: url(:/images/playButton3.png);}");

    //停止
    endButton = new QPushButton(this);
    endButton ->setToolTip(tr("停止"));
    endButton ->setObjectName(tr("endButton"));

    //上一首
    preButton = new QPushButton(this);
    preButton ->setToolTip(tr("上一首"));
    preButton ->setObjectName(tr("preButton"));

    //下一首
    nextButton = new QPushButton(this);
    nextButton ->setToolTip(tr("下一首"));
    nextButton ->setObjectName(tr("nextButton"));

    //打开文件
    openFileButton = new QPushButton(this);
    openFileButton ->setToolTip(tr("打开文件"));
    openFileButton ->setObjectName(tr("openFileButton"));

    //打开播放列表
    musicListButton = new QPushButton(this);
    musicListButton ->setToolTip(tr("打开播放列表"));
    musicListButton ->setObjectName(tr("musicListButton"));

    //桌面歌词
    lrcButton = new QPushButton(this);
    lrcButton ->setToolTip(tr("桌面歌词"));
    lrcButton ->setObjectName(tr("lrcButton"));

    //主界面退出
    closeAction = new QAction(this);
    closeAction ->setIcon(QIcon(":/images/quitAction.png"));
    closeAction ->setText(tr("退出"));

    //主界面最小化
    minAction = new QAction(this);
    minAction ->setIcon(QIcon(":/images/minAction.png"));
    minAction ->setText(tr("最小化"));

    //推盘界面退出程序
    quitAction = new QAction(this);
    quitAction ->setIcon(QIcon(":/images/quitAction.png"));
    quitAction ->setText(tr("退出"));

    //暂停(播放)
    pauseAction = new QAction(this);
    //    pauseAction ->setIcon(QIcon(":/images/trayPause.png"));
    //    pauseAction ->setText(tr("暂停"));

    //停止
    stopAction = new QAction(this);
    stopAction ->setIcon(QIcon(":/images/trayStop.png"));
    stopAction ->setText(tr("停止"));

    //上一首
    lastAction = new QAction(this);
    lastAction ->setIcon(QIcon(":/images/trayLast.png"));
    lastAction ->setText(tr("上一首"));

    //下一首
    nextAction = new QAction(this);
    nextAction ->setIcon(QIcon(":/images/trayNext.png"));
    nextAction ->setText(tr("下一首"));

    //解锁歌词
    unlockLrcAction = new QAction(this);
    unlockLrcAction ->setIcon(QIcon(":/images/unlock.png"));
    unlockLrcAction ->setText(tr("解锁歌词"));

    //打开音乐文件
    openFileAction = new QAction(this);
    openFileAction ->setIcon(QIcon(":/images/folder.png"));
    openFileAction ->setText(tr("打开音乐文件"));

    //打开播放列表
    openMusicListAction = new QAction(this);
    openMusicListAction ->setIcon(QIcon(":/images/openMusicList.png"));
    openMusicListAction ->setText(tr("打开播放列表"));

    //打开下载列表
    openMusicDownloadAction = new QAction(this);
    openMusicDownloadAction ->setIcon(QIcon(":/images/openMusicDownload.png"));
    openMusicDownloadAction ->setText(tr("打开下载列表"));

    //显示桌面歌词
    openLrcAction = new QAction(this);
    openLrcAction ->setIcon(QIcon(":/images/lrc.png"));
    openLrcAction ->setText(tr("显示桌面歌词"));

    //选项
    configAction = new QAction(this);
    configAction ->setIcon(QIcon(":/images/configButton.png"));
    configAction ->setText(tr("设置"));

    //关于Qt
    aboutQtAction = new QAction(this);
    aboutQtAction ->setIcon(QIcon(":/images/Qt.png"));
    aboutQtAction ->setText(tr("关于Qt"));

	//关于
	aboutAction = new QAction(this);
	aboutAction ->setIcon(QIcon(":/images/CZPlayer2.png"));
	aboutAction ->setText(tr("关于CZPlayer"));

    //创建系统托盘图标
    trayIcon = new QSystemTrayIcon(QIcon(":/images/CZPlayer.png"), this);
    trayIcon ->show();
    trayIcon ->showMessage(tr("CZPlayer"), tr("欢迎登陆www.highway-9.com"));
    trayIcon ->setToolTip(tr("CZPlayer"));

    //创建菜单，系统托盘图标右击出现的菜单
    trayMenu = new QMenu();
    trayMenu ->addAction(quitAction);
    trayMenu ->addAction(unlockLrcAction);
    trayMenu ->addSeparator();
    trayMenu ->addAction(pauseAction);
    trayMenu ->addAction(stopAction);
    trayMenu ->addSeparator();
    trayMenu ->addAction(lastAction);
    trayMenu ->addAction(nextAction);
    trayIcon ->setContextMenu(trayMenu);//在系统托盘上添加菜单
    trayIcon ->show();

    //小界面播放器
    minMusicWidget = new MinMusicWidget(mediaObject, &sources, this);
    //播放列表
    playList = new MusicList(mediaObject, &sources, this);
    musicListWidget = new MusicListWidget(playList, &musicInfoMap, this);
    //歌词
    lrc = new MusicLrc();
    //下载歌词
    musicDownload = new MusicDownload(this);
    //设置界面
    configDialog = new ConfigDialog(this);
	//关于CZPlayer
	aboutPanel = new AboutPanel;
    //全局热键设置
    globalHotKey = new GlobalHotKey(this);

    //设置歌词属性
	ClientBaseOperating::initLrcPropery();
    //开启全局热键
	ClientBaseOperating::initHotKeyPropery();

	//开启设备监听线程
	hotpugWatcherThread = new HotplugWatcherThread;
	//hotpugWatcherThread ->start();//在线程内部已经start

    //设置一个定时器
    timer = new QTimer(this);
    timer ->start(30);
	shortCutIimer = new QTimer(this);
	shortCutIimer ->start(500);

    //创建媒体源解析对象
    metaInformationResolver = new Phonon::MediaObject(this);
    metaInformationAudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    Phonon::createPath(metaInformationResolver, metaInformationAudioOutput);//绑定源和接收器

    //从数据库中读出信息放入音乐列表中
    this ->readFromDb();

    //设置组件大小和位置
    albumImage->setGeometry(25, 23, 110, 103);
    timeLabel ->setGeometry(295, 23, 82, 18);
    InfoLabel ->setGeometry(153, 69, 240, 39);
	lrcLabel ->setGeometry(153, 108, 240, 39);
    showButton ->setGeometry(365, 55, 17, 17);

    preButton ->setGeometry(33, 164, 25, 25);
    playButton ->setGeometry(83, 164, 25, 25);
    endButton ->setGeometry(133, 164, 25, 25);
    nextButton ->setGeometry(183, 164, 25, 25);

    seekSlider ->setGeometry(22, 137, 361, 14);
    openFileButton ->setGeometry(152, 21, 49, 23);
    musicListButton ->setGeometry(201, 20, 35, 24);
    lrcButton ->setGeometry(236, 21, 44, 23);
    volumeSlider ->setGeometry(253, 170, 128, 15);

    connect(metaInformationResolver, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(slot_MetaStateChanged(Phonon::State,Phonon::State)));
    //当媒体对象的状态发生改变时，就会自动发射stateChanged()信号，
    //这里绑定信号后，就可以用这些状态来进行一些有关的设置
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
            this, SLOT(slot_StateChanged(Phonon::State,Phonon::State)));

    connect(openFileButton, SIGNAL(clicked()), this, SLOT(slot_OpenFile()));									//打开音乐文件
    connect(musicListButton, SIGNAL(clicked()), this, SLOT(slot_OpenMusicList()));								//打开音乐列表界面
    connect(lrcButton, SIGNAL(clicked()), this, SLOT(slot_OpenMusicLrc()));										//打开歌词
    connect(showButton, SIGNAL(clicked()), this, SLOT(slot_OpenMusicDownload()));								//打开歌曲下载界面
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slot_TrayIconActivated(QSystemTrayIcon::ActivationReason)));								//推盘图标被激活后进行处理
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(slot_UpdateTime(qint64)));							//更新时间,关联媒体对象的tick信号来更新播放时间的显示
    connect(mediaObject, SIGNAL(currentSourceChanged(Phonon::MediaSource)),
            this, SLOT(slot_RowChanged(Phonon::MediaSource)));													//选中当前播放媒体源的行
    connect(mediaObject, SIGNAL(aboutToFinish()), this, SLOT(slot_AboutMusicFinish()));							//音乐播放结束
    connect(playList, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(slot_TableDoubleClicked(int, int)));		//鼠标左键双击播放列表
    connect(playList, SIGNAL(sig_PlayListClean()), this, SLOT(slot_ClearSources()));								//清空媒体源
    connect(playList, SIGNAL(sig_RowSelected(int, QString)), this, SLOT(slot_DelSelectSource(int, QString)));		//删除选中的源
    connect(lrc, SIGNAL(sig_LrcLocked()), this, SLOT(slot_ShowLrcLocked()));										//显示歌词已经锁定信息
    connect(lrc, SIGNAL(sig_LrcUnlocked()), this, SLOT(slot_ShowLrcUnlocked()));									//显示歌词已经解锁信息
    connect(unlockLrcAction, SIGNAL(triggered()), this, SLOT(slot_UnlockLrc()));								//解锁歌词
    connect(playButton, SIGNAL(clicked()), this, SLOT(slot_SetPaused()));										//暂停
    connect(endButton, SIGNAL(clicked()), this, SLOT(slot_SetStop()));											//停止
    connect(preButton, SIGNAL(clicked()), this, SLOT(slot_SetPre()));											//上一首
    connect(nextButton, SIGNAL(clicked()), this, SLOT(slot_SetNext()));											//下一首
    connect(minAction, SIGNAL(triggered()), this, SLOT(slot_MinToTray()));										//最小化
    connect(closeAction, SIGNAL(triggered()), this, SLOT(slot_CloseAllProgress()));								//退出程序
    connect(quitAction, SIGNAL(triggered()), this, SLOT(slot_CloseAllProgress()));								//退出程序
    connect(pauseAction, SIGNAL(triggered()), this, SLOT(slot_SetPaused()));									//暂停(播放)
    connect(stopAction, SIGNAL(triggered()), this, SLOT(slot_SetStop()));										//停止
    connect(lastAction, SIGNAL(triggered()), this, SLOT(slot_SetPre()));										//上一首
    connect(nextAction, SIGNAL(triggered()), this, SLOT(slot_SetNext()));										//下一首
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_TimeOut()));												//设置一个定时器
	connect(shortCutIimer, SIGNAL(timeout()), this, SLOT(slot_ShortCutsetDisable()));							//设置全局热键禁用/启用
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(slot_OpenFile()));									//打开音乐文件
    connect(openMusicListAction, SIGNAL(triggered()), this, SLOT(slot_OpenMusicList()));						//打开音乐播放列表
    connect(openMusicDownloadAction, SIGNAL(triggered()), this, SLOT(slot_OpenMusicDownload()));				//打开音乐下载列表
    connect(openLrcAction, SIGNAL(triggered()), this, SLOT(slot_OpenMusicLrc()));								//显示桌面歌词
    connect(configAction, SIGNAL(triggered()), this, SLOT(slot_ConfigCZPlayer()));								//设置
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(slot_AboutCZPlayer()));								//关于CZPlayer
    connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(slot_AboutQt()));									//关于Qt
    connect(minMusicWidget, SIGNAL(sig_OpenFileButtonClicked()), this, SLOT(slot_OpenFile()));						//打开音乐文件
    connect(minMusicWidget, SIGNAL(sig_MusicLrc()), this, SLOT(slot_OpenMusicLrc()));								//打开歌词
    connect(minMusicWidget ,SIGNAL(sig_ShowMusicPanel()), this, SLOT(slot_ShowMusicPanel()));						//显示主界面
    //    connect(minMusicWidget, SIGNAL(minPlay()), this, SLOT(slot_SetPaused()));//播放
    //    connect(minMusicWidget, SIGNAL(minPause()), this, SLOT(slot_SetPaused()));//暂停
    //    connect(minMusicWidget, SIGNAL(minStop()), this, SLOT(slot_SetStop()));//停止
    //    connect(minMusicWidget, SIGNAL(minNext()), this, SLOT(slot_SetNext()));//下一首
    //    connect(minMusicWidget, SIGNAL(minLast()), this, SLOT(slot_SetPre()));//下一首

    connect(musicListWidget, SIGNAL(sig_AddMusic()), this, SLOT(slot_OpenFile()));									//添加歌曲
	connect(musicListWidget, SIGNAL(sig_AddMusicList()), this, SLOT(slot_AddMusicList()));							//添加播放列表
    connect(this, SIGNAL(sig_ShowMainWidget()), minMusicWidget, SLOT(slot_OpenMainWidget()));					//发送到迷你界面显示主界面

	//检测设备的插入
	//QDBusConnection::systemBus().connect("org.freedesktop.Hal",
	//	"/org/freedesktop/Hal/Manager",
	//	"org.freedesktop.Hal.Manager",
	//	"DeviceAdded", this, SLOT(slotDeviceAdded(QString)));

	//检查设备的拨出
	//QDBusConnection::systemBus().connect("org.freedesktop.Hal",
	//	"/org/freedesktop/Hal/Manager",
	//	"org.freedesktop.Hal.Manager",
	//	"DeviceRemoved", this, SLOT(slotDeviceRemoved(QString)));

}

//析构函数
Widget::~Widget()
{
	if (musicDownload) {delete musicDownload; musicDownload = 0;}
	if (playList) {delete playList; playList = 0;}
	if (musicListWidget) {delete musicListWidget; musicListWidget = 0;}
	if (lrc) {delete lrc; lrc = 0;}
	if (minMusicWidget) {delete minMusicWidget; minMusicWidget = 0;}

	//terminate:终止线程
	if (hotpugWatcherThread ->isRunning()) {hotpugWatcherThread ->terminate(); delete hotpugWatcherThread; hotpugWatcherThread = 0;}
}

//从数据库中读出音乐文件信息放入音乐播放列表
void Widget::readFromDb()
{
	QStringList list;
	DBModule::readFromDb(list);
	if (list.isEmpty())
	{
		return;
	}

    sources.clear();
    //获取当前媒体源列表的大小
    int index = sources.size();

    foreach (QString str, list)
    {
        Phonon::MediaSource source(str);//将每一个音乐加载成一个源
        sources.append(source);//将每一个源添加到媒体资源列表
    }

    if (!sources.isEmpty())
    {
        //如果媒体源列表不为空，则将新加入的第一个媒体源作为当前媒体源
        metaInformationResolver ->setCurrentSource(sources.at(index));
    }

    mediaObject ->setCurrentSource(sources.at(0));
    mediaObject ->play();
    readyReadDb = 1;//已经从数据库中读出
}

//设置一个定时器
void Widget::slot_TimeOut()
{
    if (lrc ->text().isEmpty())
    {
        lrc ->stopLrcMask();
    }
    if (lrcLabel ->text().isEmpty())
    {
    }

    //如果播放列表为空，则播放按钮不能用
    if (playList ->rowCount() == 0)
    {
        playButton ->setEnabled(false);
        endButton  ->setEnabled(false);
        preButton ->setEnabled(false);
        nextButton ->setEnabled(false);

        minMusicWidget ->minPlayButton ->setEnabled(false);
        minMusicWidget ->minPauseButton ->setEnabled(false);
        minMusicWidget ->minStopButton ->setEnabled(false);
        minMusicWidget ->minNextButton ->setEnabled(false);
        minMusicWidget ->minLastButton ->setEnabled(false);

        pauseAction ->setIcon(QIcon(":/images/trayPlay.png"));
        pauseAction ->setText(tr("播放"));
        pauseAction ->setEnabled(false);
        stopAction ->setEnabled(false);
        lastAction ->setEnabled(false);
        nextAction ->setEnabled(false);
    }
    else
    {
        playButton ->setEnabled(true);
        endButton  ->setEnabled(true);
        preButton ->setEnabled(true);
        nextButton ->setEnabled(true);

        minMusicWidget ->minPlayButton ->setEnabled(true);
        minMusicWidget ->minPauseButton ->setEnabled(true);
        minMusicWidget ->minStopButton ->setEnabled(true);
        minMusicWidget ->minNextButton ->setEnabled(true);
        minMusicWidget ->minLastButton ->setEnabled(true);

        pauseAction ->setEnabled(true);
        stopAction ->setEnabled(true);
        lastAction ->setEnabled(true);
        nextAction ->setEnabled(true);
    }
}

//选项设置
void Widget::slot_ConfigOptions()
{
    if (configDialog ->isHidden())
    {
        this ->slot_ConfigCZPlayer();
    }
}

//显示/隐藏主界面
void Widget::slot_ShowHideMainWidget()
{
    this ->slot_MinToTray();
    if (this ->isHidden())
    {
        this ->slot_TrayIconActivated(QSystemTrayIcon::Trigger);
    }
}

//迷你模式/正常窗口
void Widget::slot_MinMainWidget()
{
    this ->slot_OpenMinWidget();
    if (this ->isHidden())
    {
        emit sig_ShowMainWidget();//显示主界面
    }
}

//打开音乐文件
void Widget::slot_OpenMusicfile()
{
    this ->slot_OpenFile();
}

//显示/隐藏下载列表
void Widget::slot_ShowDownload()
{
    this ->slot_OpenMusicDownload();
}

//显示/隐藏歌曲列表
void Widget::slot_ShowMusicList()
{
    this ->slot_OpenMusicList();
}

//显示/隐藏桌面歌词
void Widget::slot_ShowLrc()
{
    this ->slot_OpenMusicLrc();
}

//播放/暂停
void Widget::slot_PlayPause()
{
    this ->slot_SetPaused();
}

//上一首
void Widget::slot_Last()
{
    this ->slot_SetPre();
}

//下一首
void Widget::slot_Next()
{
    this ->slot_SetNext();
}

//打开文件
void Widget::slot_OpenFile()
{
    //可以同时打开多个音频文件
#ifdef _WIN32_WINNT
    QString WINPATH = CZPlayerConfig::getValue("MUSICDIR_WIN").toString();
    QStringList list = QFileDialog::getOpenFileNames(this, tr("打开音乐文件"),
                                                     WINPATH, tr("music Files(*.mp3 *.wav *.wma *ogg)"));
#else
    QString X11PATH =  QDir::homePath() + CZPlayerConfig::getValue("MUSICDIR_X11").toString();
    QStringList list = QFileDialog::getOpenFileNames(this, tr("打开音乐文件"),
                                                     X11PATH, tr("music Files(*.mp3 *.wav *.wma *ogg)"));
#endif

    if (list.isEmpty())
    {
        return;
    }
    //获取当前媒体源列表的大小
    int index = sources.size();

    foreach (QString str, list)
    {
        Phonon::MediaSource source(str);//将每一个音乐加载成一个源
        sources.append(source);//将每一个源添加到媒体资源列表
    }

    if (!sources.isEmpty())
    {
        //如果媒体源列表不为空，则将新加入的第一个媒体源作为当前媒体源
        metaInformationResolver ->setCurrentSource(sources.at(index));
    }

    int static count = 0;
    ++count;
    if (count == 1 && readyReadDb == 0)//第一次打开文件并且没有从数据库中读取
    {
        mediaObject ->setCurrentSource(sources.at(0));
        mediaObject ->play();
    }
}

//添加播放列表
void Widget::slot_AddMusicList()
{
	//只能打开一个播放列表文件
#ifdef _WIN32_WINNT
	QString WINPATH = CZPlayerConfig::getValue("MUSICDIR_WIN").toString();
	QString fileName = QFileDialog::getOpenFileName(this, tr("载入播放列表"),
		WINPATH, tr("music List(*.m3u *.pls)"));
#else
	QString X11PATH =  QDir::homePath() + CZPlayerConfig::getValue("MUSICDIR_X11").toString();
	QString fileName = QFileDialog::getOpenFileName(this, tr("载入播放列表"),
		WINPATH, tr("music List(*.m3u *.pls)"));
#endif

	if (fileName != "")
	{
		QString strSuffixName = fileName.right(3);//得到后缀名
		//获取当前媒体源列表的大小
		int index = sources.size();
		char buf[256];
		string sBuf;
		int i = 0;
		int n = 1;
		ifstream file(fileName.toStdString());
		while (!file.eof())
		{
			file.getline(buf, 256, '\n');
			sBuf = buf;

			if (i == 0)		//读取表头
			{
				if (sBuf != "#EXTM3U" && sBuf != "[playlist]")
				{
					QMessageBox::information(NULL, tr("信息"), tr("不是有效的m3u或pls文件！"), QMessageBox::Yes);
					return;
				}
			}
			else
			{
				if ((strSuffixName == "m3u" || strSuffixName == "M3U") && i % 2 == 0)
				{
					Phonon::MediaSource source(QString::fromStdString(sBuf));//将每一个音乐加载成一个源
					sources.append(source);//将每一个源添加到媒体资源列表
				}
				else if ((strSuffixName == "pls" || strSuffixName == "PLS") && i == 1 + (n - 1) * 3)
				{
					if (!QString::fromStdString(sBuf).contains("NumberOfEntries"))
					{
						++n;
						if (QString::fromStdString(sBuf).contains("="))
						{
							QStringList list = QString::fromStdString(sBuf).split("=");
							QString filePath = list.at(1);
							Phonon::MediaSource source(filePath);//将每一个音乐加载成一个源
							sources.append(source);//将每一个源添加到媒体资源列表
						}
					}
				}
			}
			++i;
		}
		file.close();

		if (!sources.isEmpty())
		{
			//如果媒体源列表不为空，则将新加入的第一个媒体源作为当前媒体源
			metaInformationResolver ->setCurrentSource(sources.at(index));
		}

		int static count = 0;
		++count;
		if (count == 1 && readyReadDb == 0)//第一次打开文件并且没有从数据库中读取
		{
			mediaObject ->setCurrentSource(sources.at(0));
			mediaObject ->play();
		}
	}
}

//开启小界面
void Widget::slot_OpenMinWidget()
{
    if (minMusicWidget ->isHidden())
    {
        QPropertyAnimation *minWidgetdAnimation = new QPropertyAnimation(minMusicWidget, "windowOpacity");
        minWidgetdAnimation ->setDuration(500);
        minWidgetdAnimation ->setStartValue(0);
        minWidgetdAnimation ->setEndValue(1);
        minWidgetdAnimation ->start();
        minMusicWidget ->show();

        QPropertyAnimation *mainWidgetdAnimation = new QPropertyAnimation(this, "windowOpacity");
        mainWidgetdAnimation ->setDuration(500);
        mainWidgetdAnimation ->setStartValue(1);
        mainWidgetdAnimation ->setEndValue(0);
        mainWidgetdAnimation ->start();
        connect(mainWidgetdAnimation, SIGNAL(finished()), this, SLOT(slot_HideMainWidget()));

        QPropertyAnimation *musicDownloadAnimation = new QPropertyAnimation(musicDownload, "windowOpacity");
        musicDownloadAnimation ->setDuration(500);
        musicDownloadAnimation ->setStartValue(1);
        musicDownloadAnimation ->setEndValue(0);
        musicDownloadAnimation ->start();
        connect(musicDownloadAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicDownload()));

        QPropertyAnimation *musicListAnimation = new QPropertyAnimation(musicListWidget, "windowOpacity");
        musicListAnimation ->setDuration(500);
        musicListAnimation ->setStartValue(1);
        musicListAnimation ->setEndValue(0);
        musicListAnimation ->start();
        connect(musicListAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicList()));
    }
}

//打开播放列表
void Widget::slot_OpenMusicList()
{
    if (musicListWidget ->isHidden())
    {
        musicListWidget ->move(frameGeometry().bottomLeft());//显示在主界面的下方
        QPropertyAnimation *musicListAnimation = new QPropertyAnimation(musicListWidget, "windowOpacity");
        musicListAnimation ->setDuration(500);
        musicListAnimation ->setStartValue(0);
        musicListAnimation ->setEndValue(1);
        musicListAnimation ->start();
        musicListWidget ->show();
        openMusicListAction ->setText(tr("关闭播放列表"));
        musicListShowFlag = 1;
    }
    else
    {
        QPropertyAnimation *musicListAnimation = new QPropertyAnimation(musicListWidget, "windowOpacity");
        musicListAnimation ->setDuration(500);
        musicListAnimation ->setStartValue(1);
        musicListAnimation ->setEndValue(0);
        musicListAnimation ->start();
        connect(musicListAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicList()));
        openMusicListAction ->setText(tr("打开播放列表"));
        musicListShowFlag = 0;
    }
}

//打开歌词
void Widget::slot_OpenMusicLrc()
{
    if (lrc ->isHidden())
    {
        //lrc ->show();
        lrc ->showNormal();
        openLrcAction ->setText(tr("关闭桌面歌词"));
        minMusicWidget ->minMusicLrcAction ->setText(tr("关闭桌面歌词"));
    }
    else
    {
        lrc ->hide();
        openLrcAction ->setText(tr("显示桌面歌词"));
        minMusicWidget ->minMusicLrcAction ->setText(tr("显示桌面歌词"));
    }
}

//打开下载歌曲界面
void Widget::slot_OpenMusicDownload()
{
    if (musicDownload ->isHidden())
    {
        musicDownload ->move(frameGeometry().topRight());//显示在主界面的右方
        QPropertyAnimation *downloadAnimation = new QPropertyAnimation(musicDownload, "windowOpacity");
        downloadAnimation ->setDuration(500);
        downloadAnimation ->setStartValue(0);
        downloadAnimation ->setEndValue(1);
        downloadAnimation ->start();
        musicDownload ->show();
        openMusicDownloadAction ->setText(tr("关闭下载列表"));
        showButton ->setToolTip(tr("关闭下载列表"));
        showButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/hideButton.png);}"
                                   "QPushButton:hover{border-image: url(:/images/hideButton2.png);}"
                                   "QPushButton:pressed{border-image: url(:/images/hideButton3.png);}");
        musicDownloadShowFlag = 1;
    }
    else
    {
        QPropertyAnimation *downloadAnimation = new QPropertyAnimation(musicDownload, "windowOpacity");
        downloadAnimation ->setDuration(500);
        downloadAnimation ->setStartValue(1);
        downloadAnimation ->setEndValue(0);
        downloadAnimation ->start();
        connect(downloadAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicDownload()));
        openMusicDownloadAction ->setText(tr("打开下载列表"));
        showButton ->setToolTip(tr("打开下载列表"));
        showButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/showButton.png);}"
                                   "QPushButton:hover{border-image: url(:/images/showButton2.png);}"
                                   "QPushButton:pressed{border-image: url(:/images/showButton3.png);}");
        musicDownloadShowFlag = 0;
    }
}

//隐藏下载歌曲界面
void Widget::slot_HideMusicDownload()
{
    musicDownload ->hide();
}

//隐藏音乐播放器列表
void Widget::slot_HideMusicList()
{
    musicListWidget ->hide();
}

//隐藏主界面
void Widget::slot_HideMainWidget()
{
    this ->hide();
}

//显示主界面
void Widget::slot_ShowMusicPanel()
{
    if (musicDownloadShowFlag == 1)
    {
        this ->slot_OpenMusicDownload();
    }
    if (musicListShowFlag == 1)
    {
        this ->slot_OpenMusicList();
    }
}

//设置
void Widget::slot_ConfigCZPlayer()
{
    ConfigDialog::contentsWidget ->setCurrentRow(0);//选中第一页
	ClientBaseOperating::initConfigDialog();//初始化设置对话框
    configDialog ->exec();//模态显示对话框
}

//关于Qt
void Widget::slot_AboutQt()
{
    QMessageBox::aboutQt(this, "关于Qt");
}

//关于CZPlayer
void Widget::slot_AboutCZPlayer()
{
	AboutPanel::tabWidget ->setCurrentIndex(0);
	aboutPanel ->exec();//模态显示对话框
}

//解析LRC歌词，在stateChanged()函数的Phonon::PlayingState处(解析当前播放歌的歌词)
//和slot_AboutMusicFinish()函数中调用了该函数(开始解析下一首歌的歌词)
void Widget::resolveLrc(const QString &sourceFileName)
{
    lrcMap.clear();
    if (sourceFileName.isEmpty())
    {
        return;
    }

    QString lrcFileInfo = QFileInfo(mediaObject ->currentSource().fileName()).baseName();
#ifdef _WIN32_WINNT
    QString lrcDirName = CZPlayerConfig::getValue("LRCDIR_WIN").toString();
#else
    QString lrcDirName = QDir::homePath() + CZPlayerConfig::getValue("LRCDIR_X11").toString();
#endif
    QString lrcFileName = lrcDirName + "/" + lrcFileInfo + ".lrc";
    m_lrcFileName = lrcFileName;

    //加载专辑图片
    QString fileNameInfo = QFileInfo(mediaObject ->currentSource().fileName()).baseName();
    if (!fileNameInfo.contains(" - "))//没有包含该字符串(格式为：光辉岁月)
    {
        QString name = fileNameInfo;//歌曲名
        int index = sources.indexOf(mediaObject ->currentSource());
        QTableWidgetItem *item = playList ->item(index, 2);
        QString artist = item ->text();//歌手

#ifdef _WIN32_WINNT
    QString albumImagesName = CZPlayerConfig::getValue("ALBUMDIR_WIN").toString();
#else
    QString albumImagesName = QDir::homePath() + CZPlayerConfig::getValue("ALBUMDIR_X11").toString();
#endif

        QString albumFileName = albumImagesName + "/" + artist + " - " + name + ".jpg";
        QFile fileAlbum(albumFileName);
        if (fileAlbum.open(QIODevice::ReadOnly))//打开文件成功
        {
			//由于下载出错，没能下载完
			if (fileAlbum.size() <  4500)
			{
				//下载专辑图片
				AlbumThread *albumThread = new AlbumThread(name, artist, albumImage);
				albumThread ->start();//开启一个线程
			}
			else
			{
				albumImage ->setPixmap(QPixmap(albumFileName));
			}
        }
        else
        {
            //下载专辑图片
            AlbumThread *albumThread = new AlbumThread(name, artist, albumImage);
            albumThread ->start();//开启一个线程
        }
    }
    else//包含该字符串（格式为：光辉岁月 - 黄家驹）
    {
        //打开专辑图片
        QStringList ablumList = fileNameInfo.split(" - ");
        QString name = ablumList.at(1);//歌曲名
        QString artist = ablumList.at(0);//歌手

#ifdef _WIN32_WINNT
    QString albumImagesName = CZPlayerConfig::getValue("ALBUMDIR_WIN").toString();
#else
    QString albumImagesName = QDir::homePath() + CZPlayerConfig::getValue("ALBUMDIR_X11").toString();
#endif

        QString albumFileName = albumImagesName + "/" + artist + " - " + name + ".jpg";
        QFile fileAlbum(albumFileName);
        if (fileAlbum.open(QIODevice::ReadOnly))//打开文件成功
        {
            //由于下载出错，没能下载完
            if (fileAlbum.size() <  4500)
            {
                //下载专辑图片
                AlbumThread *albumThread = new AlbumThread(name, artist, albumImage);
                albumThread ->start();//开启一个线程
            }
            else
            {
                albumImage ->setPixmap(QPixmap(albumFileName));
            }
        }
        else
        {
            //下载专辑图片
            AlbumThread *albumThread = new AlbumThread(name, artist, albumImage);
            albumThread ->start();//开启一个线程
        }
    }

    //打开歌词
    QFile file(lrcFileName);
    if (!file.open(QIODevice::ReadOnly))//下载歌曲文件
    {
        lrc ->setText(QFileInfo(mediaObject ->currentSource().fileName()).baseName() +
                      tr("----正在下载歌词文件!"));

        QString fileInfo = QFileInfo(mediaObject ->currentSource().fileName()).baseName();
        if (!fileInfo.contains(" - "))//没有包含该字符串
        {
            QString musicName = fileNameInfo;//歌曲名
            int index = sources.indexOf(mediaObject ->currentSource());
            QTableWidgetItem *item = playList ->item(index, 1);
            QString musicArtist = item ->text();//歌手

			//下载歌词
			LrcThread *lrcThread = new LrcThread(musicName, musicArtist, m_lrcFileName, lrc);
			lrcThread ->start();//开启一个线程
			connect(lrcThread, SIGNAL(sig_ResolveLrc()), this, SLOT(slot_ResolveLrc()));
            return;
        }
        else
        {
            QStringList list = fileInfo.split(" - ");
            QString musicName = list.at(1);//歌曲名
            QString musicArtist = list.at(0);//歌手

			//下载歌词
			LrcThread *lrcThread = new LrcThread(musicName, musicArtist, m_lrcFileName, lrc);
			lrcThread ->start();//开启一个线程
			connect(lrcThread, SIGNAL(sig_ResolveLrc()), this, SLOT(slot_ResolveLrc()));
            return;
        }
    }

    QString allText = QString(file.readAll());
    file.close();

    //将歌词安行分为歌词列表
    QStringList lrcLines = allText.split("\n");

    //这个是时间标签的格式[00:05.54]
    //正则表达式\d{2}表示匹配两个数字
    QRegExp rx("\\[\\d{2}:\\d{2}\\.\\d{2}\\]");

    foreach (QString oneLine, lrcLines)
    {
        QString temp = oneLine;
        temp.replace(rx, "");//用空字符串替换正则表达式中所匹配的地方,这样就获得了歌词文本

        // 然后依次获取当前行中的所有时间标签，并分别与歌词文本存入QMap中
        //indexIn()为返回第一个匹配的位置，如果返回为-1，则表示没有匹配成功
        //正常情况下pos后面应该对应的是歌词文件

        int pos = rx.indexIn(oneLine, 0);
        while (pos != -1)//表示匹配成功
        {
            QString cap = rx.cap(0);//返回第0个表达式匹配的内容

            //将时间标签转换为时间数值，以毫秒为单位
            QRegExp regexp;

            //获得分钟
            regexp.setPattern("\\d{2}(?=:)");
            regexp.indexIn(cap);
            int minute = regexp.cap(0).toInt();

            //获得秒
            regexp.setPattern("\\d{2}(?=\\.)");
            regexp.indexIn(cap);
            int second = regexp.cap(0).toInt();

            //获得毫秒
            regexp.setPattern("\\d{2}(?=\\])");
            regexp.indexIn(cap);
            int milliseSecond = regexp.cap(0).toInt();

            //获得总时间
            qint64 totalTime = minute * 60000 + second * 1000 + milliseSecond * 10;

            //把每一行的时间和歌词插入到lrcMap中
            lrcMap.insert(totalTime, temp);
            pos += rx.matchedLength();
            pos = rx.indexIn(oneLine, pos);//匹配全部
        }
    }

    //如果lrcMap为空
    if (lrcMap.isEmpty())
    {
        lrc ->setText(QFileInfo(mediaObject ->currentSource().fileName()).baseName()
                      + tr("----歌词文件内容错误!"));
        return;
    }
}

//调用解析歌词
void Widget::slot_ResolveLrc()
{
	this ->resolveLrc(mediaObject ->currentSource().fileName());//解析当前下载歌词
}

//更新时间
void Widget::slot_UpdateTime(qint64 time)
{
    qint64 totalTimeValue = mediaObject ->totalTime();//设置获取该音频文件的总时长参数，单位为毫秒
    //这3个参数分别代表了时,分,秒,60000毫秒为1分钟,
    //所以分钟第二个参数是先除60000,第3个参数是直接除1s
    QTime totalTime(0, (totalTimeValue / 60000) % 60, (totalTimeValue / 1000) % 60);
    QTime currentTime(0, (time / 60000) % 60, (time / 1000) % 60);
    QString str = currentTime.toString("mm:ss") + "/" + totalTime.toString("mm:ss");
    timeLabel ->setText(str);

    //获取当前时间对应的歌词
    if (!lrcMap.isEmpty())
    {
        //获取当前时间在歌词中的前后两个时间点
        qint64 previousTime = 0;
        qint64 laterTime = 0;

        //keys()方法返回lrcMap列表
        foreach (qint64 value, lrcMap.keys())
        {
            if (time >= value)
            {
                previousTime = value;
            }
            else
            {
                laterTime = value;
                break;
            }
        }

        // 达到最后一行,将laterTime设置为歌曲总时间的值
        if (laterTime == 0)
        {
            laterTime = totalTimeValue;
        }

        //获取当前时间所对应的歌词内容
        QString currentLrc = lrcMap.value(previousTime);

        // 如果是新的一行歌词，那么重新开始显示歌词遮罩
        if (currentLrc != lrc ->text())
        {
            lrc ->setText(currentLrc);
			lrcLabel ->setText(currentLrc);
            qint64 intervalTime = laterTime - previousTime;//时间间隔
            lrc ->startLrcMask(intervalTime);//开启歌词遮罩
        }
    }
    else
    {
        lrc ->setText(QFileInfo(mediaObject ->currentSource().fileName()).baseName() +
                      tr("----未找到歌词文件!"));
		lrcLabel ->setText(tr("highway-9"));
    }
}

//暂停播放
void Widget::slot_SetPaused()
{
    if (mediaObject ->state() == Phonon::PlayingState)
    {
        mediaObject ->pause();
    }
    else
    {
        mediaObject ->play();
    }
}

//停止播放
void Widget::slot_SetStop()
{
    if (mediaObject ->state() == Phonon::PlayingState || mediaObject ->state() == Phonon::PausedState)
    {
        mediaObject ->stop();
    }
}

//播放上一首
void Widget::slot_SetPre()
{
    //QMovie *movie = new QMovie(tr(":/images/jiaZai.gif"));
    albumImage ->setPixmap(QPixmap(tr("")));
    albumImage ->setMovie(movie);
    movie ->start();
    int index = sources.indexOf(mediaObject ->currentSource());
    if (index != 0)//如果当前首不为第一首，则播放上一首
    {
        mediaObject ->setCurrentSource(sources.at(index - 1));
        mediaObject ->play();
    }
}

//播放下一首
void Widget::slot_SetNext()
{
    //QMovie *movie = new QMovie(tr(":/images/jiaZai.gif"));
    albumImage ->setPixmap(QPixmap(tr("")));
    albumImage ->setMovie(movie);
    movie ->start();
    int index = sources.indexOf(mediaObject ->currentSource()) + 1;
    if (sources.size() > index)//如果当前首不为最后一首，则播放下一首
    {
        mediaObject ->setCurrentSource(sources.at(index));
        mediaObject ->play();
    }
}

//该槽函数是当媒体源发生改变时，触发currentSourceChanged()信号，从而执行该槽函数
//该函数完成的功能是选中所改变的媒体源的那一行
void Widget::slot_RowChanged(const Phonon::MediaSource &source)
{
    albumImage ->setPixmap(QPixmap(tr("")));
    albumImage ->setMovie(movie);
    movie ->start();
    int index = sources.indexOf(source);
    playList ->selectRow(index);
}

//鼠标左键双击音乐播放列表选中行
void Widget::slot_TableDoubleClicked(int row, int /*column*/)
{
    //bool wasPlaying = mediaObject ->state() == Phonon::PlayingState;

    mediaObject ->stop();//停止当前歌曲的播放
    mediaObject ->clearQueue();//清除播放队列

    //如果选中的行大于媒体源最大行，则返回
    if (row >= sources.size())
    {
        return;
    }

    mediaObject ->setCurrentSource(sources.at(row));
    mediaObject ->play();

}

//清空媒体源并且删除数据库全部数据和map
void Widget::slot_ClearSources()
{
    sources.clear();
    mediaObject ->stop();
    mediaObject ->clear();

	if (!DBModule::clearDB())//清空数据库
	{
		QMessageBox::information(NULL, tr("信息"), tr("清空数据库失败！"), QMessageBox::Yes);
	}

    musicInfoMap.clear();
    albumImage ->setPixmap(QPixmap(tr(":/images/albumImage.png")));
}

//删除选中的源并且删除数据库相应的数据
void Widget::slot_DelSelectSource(int row, QString title)
{
    //如果删除的当前行为正在播放的那一行，则停止该音乐的播放
    if (row == sources.indexOf(mediaObject ->currentSource()))
    {
        mediaObject ->stop();
    }
    sources.removeAt(row);

	if (!DBModule::delLine(title))//删除一行
	{
		QMessageBox::information(NULL, tr("信息"), tr("删除该歌曲失败！"), QMessageBox::Yes);
		return;
	}

    //更新map
    this ->updateMap();
}

//更新map
void Widget::updateMap()
{
    musicInfoMap.clear();
    for (int index = 0; index < playList ->rowCount(); ++index)
    {
        QTableWidgetItem *musicNameItem = playList ->item(index, 1);
        QString musicName = musicNameItem ->text();//歌曲名
        QTableWidgetItem *artistItem = playList ->item(index, 2);
        QString artist = artistItem ->text();//歌手
        QString str = musicName + "-" + artist;
        musicInfoMap.insert(make_pair(str, index));
    }
}

//当媒体播放快结束时，会发送aboutToFininsh()信号
void Widget::slot_AboutMusicFinish()
{
    int index = sources.indexOf(mediaObject ->currentSource()) + 1;
    if (sources.size() > index)
    {
        mediaObject ->setCurrentSource(sources.at(index));
        mediaObject ->play();
        lrc ->stopLrcMask();//停止歌词遮罩
        resolveLrc(sources.at(index).fileName());//解析下一首歌的歌词
    }
    else
    {
        mediaObject ->enqueue(sources.at(0));
        mediaObject ->play();
        lrc ->stopLrcMask();//停止歌词遮罩
        resolveLrc(sources.at(0).fileName());//解析下一首歌的歌词
        QString fileName = QFileInfo(sources.at(0).fileName()).baseName();
        InfoLabel ->setText(fileName);
    }
}

//更改一些状态设置
void Widget::slot_StateChanged(Phonon::State newState, Phonon::State /*oldState*/)
{
    QString fileName;
    QString fileName2;
    switch (newState)
    {
    //当新状态为错误状态时
    //    case Phonon::ErrorState:
    //        if (mediaObject ->errorType() == Phonon::FatalError)
    //        {
    //            QMessageBox::warning(this, tr("致命错误!"), mediaObject ->errorString());
    //        }
    //        else
    //        {
    //            QMessageBox::warning(this, tr("错误!"), mediaObject ->errorString());
    //        }
    //        break;

    //当新状态为播放状态时，更改一些控件的状态
    case Phonon::PlayingState:
        playButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/stopButton.png);}"
                                   "QPushButton:hover{border-image: url(:/images/stopButton2.png);}"
                                   "QPushButton:pressed{border-image: url(:/images/stopButton3.png);}");
        playButton ->setToolTip(tr("暂停"));
        pauseAction ->setIcon(QIcon(":/images/trayPause.png"));
        pauseAction ->setText(tr("暂停"));
        fileName = QFileInfo(mediaObject ->currentSource().fileName()).baseName();
        InfoLabel ->setText(fileName);
        trayIcon ->setToolTip(tr("正在播放:%1").arg(fileName));
        resolveLrc(mediaObject ->currentSource().fileName());//解析正在播放的歌曲的歌词
        break;

        //新状态为暂停状态
    case Phonon::PausedState:
        playButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/playButton.png);}"
                                   "QPushButton:hover{border-image: url(:/images/playButton2.png);}"
                                   "QPushButton:pressed{border-image: url(:/images/playButton3.png);}");
        playButton ->setToolTip(tr("播放"));
        pauseAction ->setIcon(QIcon(":/images/trayPlay.png"));
        pauseAction ->setText(tr("播放"));
        fileName2 = QFileInfo(mediaObject ->currentSource().fileName()).baseName();
        fileName2 += "\n暂停";
        InfoLabel ->setText(fileName2);
        trayIcon ->setToolTip(tr("CZPlayer"));
        lrc ->stopLrcMask();
        lrc ->setText(QFileInfo(mediaObject ->currentSource().fileName()).baseName());
		lrcLabel ->setText(tr("highway-9"));
        break;

        //新状态为停止播放
    case Phonon::StoppedState:
        playButton ->setStyleSheet("QPushButton:!hover{border-image: url(:/images/playButton.png);}"
                                   "QPushButton:hover{border-image: url(:/images/playButton2.png);}"
                                   "QPushButton:pressed{border-image: url(:/images/playButton3.png);}");
        playButton ->setToolTip(tr("播放"));
        pauseAction ->setIcon(QIcon(":/images/trayPlay.png"));
        pauseAction ->setText(tr("播放"));
        timeLabel ->setText(tr("00:00/00:00"));
        InfoLabel ->setText(tr("Welecome to CZPlayer!"));
        trayIcon ->setToolTip(tr("CZPlayer"));
        lrc ->stopLrcMask();
        lrc ->setText(tr("CZPlayer"));
		lrcLabel ->setText(tr("highway-9"));
        break;

    case Phonon::BufferingState:
        break;

    default:
        break;
    }
}

//媒体源改变时，添加新的源
void Widget::slot_MetaStateChanged(Phonon::State newState, Phonon::State /*oldState*/)
{
    //错误状态，则从媒体源列表中除去新添加的媒体源
    if (newState == Phonon::ErrorState)
    {
        QMessageBox::warning(this, tr("打开文件时出错!"), metaInformationResolver ->errorString());
        //takeLast()为删除最后一行并将其返回
        while (!sources.isEmpty() && !(sources.takeLast() == metaInformationResolver ->currentSource()))
        {

        }//只留下最后一行
        return;
    }

    //如果既不处于停止状态也不处于暂停状态，则直接返回
    if (newState != Phonon::StoppedState && newState != Phonon::PausedState)
    {
        return;
    }

    //如果媒体源类型错误，则直接返回
    if (metaInformationResolver ->currentSource().type() == Phonon::MediaSource::Invalid)
    {
        return;
    }

    QMap<QString, QString> metadata = metaInformationResolver ->metaData();//获取媒体源中的源数据

    //获取文件标题信息
    QString title;
    QString filePath = metaInformationResolver ->currentSource().fileName();
    if (!QFileInfo(filePath).baseName().contains(" - "))//没有包含该字符串
    {
        title = metadata.value("TITLE");
        if (title == "")
        {
            title = "unKown";
        }
    }
    else
    {
        QStringList str = QFileInfo(filePath).baseName().split(" - ");
        title = str.at(1);
    }
    QTableWidgetItem *titleItem = new QTableWidgetItem(title);
    titleItem ->setTextAlignment(Qt::AlignCenter);

    //获取艺术家信息
    QString artist = "unKown";
    if (!QFileInfo(filePath).baseName().contains(" - "))//没有包含该字符串
    {
        artist = metadata.value("ARTIST");
        if (artist == "")
        {
            artist = "unKown";
        }
    }
    else
    {
        QStringList str = QFileInfo(filePath).baseName().split(" - ");
        artist = str.at(0);
    }
    QTableWidgetItem *artistItem = new QTableWidgetItem(artist);
    artistItem ->setTextAlignment(Qt::AlignCenter);

    //Album获取专辑信息
    //QTableWidgetItem *albumItem = new QTableWidgetItem(metadata.value("DATE"));

    //获取总时间信息
    qint64 totalTime = metaInformationResolver ->totalTime();
    QTime time(0, (totalTime / 60000) % 60, (totalTime / 1000) % 60);
    QTableWidgetItem *timeItem = new QTableWidgetItem(time.toString("mm:ss"));
    timeItem ->setTextAlignment(Qt::AlignCenter);

    //序号
    QTableWidgetItem *rowItem = new QTableWidgetItem;
    rowItem ->setTextAlignment(Qt::AlignCenter);

    //插入播放列表
    int currentRows = playList ->rowCount();//返回列表中的行数
    playList ->insertRow(currentRows);//从播放列表中的当前行插入
    rowItem ->setText(QString::number(currentRows + 1));
    playList ->setItem(currentRows, 0, rowItem);
    playList ->setItem(currentRows, 1, titleItem);
    playList ->setItem(currentRows, 2, artistItem);
    //playList ->setItem(currentRows, 2, albumitem);
    playList ->setItem(currentRows, 3, timeItem);

    //更改时间列间隔
    if (currentRows + 1 <= 12)
    {
        playList ->horizontalHeader() ->resizeSection(3, 80);
    }
    else
    {
        playList ->horizontalHeader() ->resizeSection(3, 65);
    }

    //将音乐信息加入vector
    QString musicInfoStr = title + "-" + artist;
    musicInfoMap.insert(make_pair(musicInfoStr, currentRows));

	//放入数据库
	DBModule::insertLine(title, artist, time.toString("mm:ss"), filePath);

    //sources为打开的所有音频文件列表，playList为音乐播放列表表格对象
    int index = sources.indexOf(metaInformationResolver ->currentSource()) + 1;
    if (sources.size() > index)//没有解析完
    {
        metaInformationResolver ->setCurrentSource(sources.at(index));
    }
    else
    {
        //没有被选中的行
        if (playList ->selectedItems().isEmpty())
        {
            //如果现在没有播放歌曲则设置第一个媒体源为媒体对象的当前媒体源
            //因为可能正在播放歌曲时清空了播放列表，然后又添加了新的列表
            if (mediaObject ->state() != Phonon::PlayingState
                    && mediaObject ->state() != Phonon::PausedState)
            {
                mediaObject ->setCurrentSource(sources.at(0));
                mediaObject ->play();
            }
            else
            {
                //如果正在播放歌曲，则选中播放列表的第一个曲目，并更改图标状态
                playList ->selectRow(0);
            }
        }
    }
}

//最小化到托盘
void Widget::slot_MinToTray()
{
    if (musicListWidget ->isVisible())
    {
        QPropertyAnimation *musicListAnimation = new QPropertyAnimation(musicListWidget, "windowOpacity");
        musicListAnimation ->setDuration(500);
        musicListAnimation ->setStartValue(1);
        musicListAnimation ->setEndValue(0);
        musicListAnimation ->start();
        connect(musicListAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicList()));
    }
    if (musicDownload ->isVisible())
    {
        QPropertyAnimation *musicDownloadAnimation = new QPropertyAnimation(musicDownload, "windowOpacity");
        musicDownloadAnimation ->setDuration(500);
        musicDownloadAnimation ->setStartValue(1);
        musicDownloadAnimation ->setEndValue(0);
        musicDownloadAnimation ->start();
        connect(musicDownloadAnimation, SIGNAL(finished()), this, SLOT(slot_HideMusicDownload()));
    }
    if (this ->isVisible())
    {
        QPropertyAnimation *mainWidgetAnimation = new QPropertyAnimation(this, "windowOpacity");
        mainWidgetAnimation ->setDuration(500);
        mainWidgetAnimation ->setStartValue(1);
        mainWidgetAnimation ->setEndValue(0);
        mainWidgetAnimation ->start();
        connect(mainWidgetAnimation, SIGNAL(finished()), this, SLOT(slot_HideMainWidget()));
        trayIcon ->showMessage(tr("CZPlayer"), tr("单击我重新回到主界面"));
    }
}

//关闭所有程序
void Widget::slot_CloseAllProgress()
{
    //    mediaObject ->stop();
    //    sources.clear();

    QPropertyAnimation *mainWidgetAnimation = new QPropertyAnimation(this, "windowOpacity");
    mainWidgetAnimation ->setDuration(500);
    mainWidgetAnimation ->setStartValue(1);
    mainWidgetAnimation ->setEndValue(0);
    mainWidgetAnimation ->start();
    connect(mainWidgetAnimation, SIGNAL(finished()), this, SLOT(close()));

    QPropertyAnimation *musicListAnimation = new QPropertyAnimation(musicListWidget, "windowOpacity");
    musicListAnimation ->setDuration(500);
    musicListAnimation ->setStartValue(1);
    musicListAnimation ->setEndValue(0);
    musicListAnimation ->start();
    connect(musicListAnimation, SIGNAL(finished()), this, SLOT(close()));

    QPropertyAnimation *musicDownloadAnimation = new QPropertyAnimation(musicDownload, "windowOpacity");
    musicDownloadAnimation ->setDuration(500);
    musicDownloadAnimation ->setStartValue(1);
    musicDownloadAnimation ->setEndValue(0);
    musicDownloadAnimation ->start();
    connect(musicDownloadAnimation, SIGNAL(finished()), this, SLOT(close()));

    QPropertyAnimation *lrcAnimation = new QPropertyAnimation(lrc, "windowOpacity");
    lrcAnimation ->setDuration(500);
    lrcAnimation ->setStartValue(1);
    lrcAnimation ->setEndValue(0);
    lrcAnimation ->start();
    connect(lrcAnimation, SIGNAL(finished()), this, SLOT(close()));

    minMusicWidget ->close();
    //    QPropertyAnimation *minWidgetAnimation = new QPropertyAnimation(minMusicWidget, "windowOpacity");
    //    minWidgetAnimation ->setDuration(500);
    //    minWidgetAnimation ->setStartValue(1);
    //    minWidgetAnimation ->setEndValue(0);
    //    minWidgetAnimation ->start();
    //    connect(minWidgetAnimation, SIGNAL(finished()), this, SLOT(close()));
}

//系统托盘图标被激活
void Widget::slot_TrayIconActivated(QSystemTrayIcon::ActivationReason activationReason)
{
    if (activationReason == QSystemTrayIcon::Trigger)
    {
        QPropertyAnimation *mainWidgetAnimation = new QPropertyAnimation(this, "windowOpacity");
        mainWidgetAnimation ->setDuration(500);
        mainWidgetAnimation ->setStartValue(0);
        mainWidgetAnimation ->setEndValue(1);
        mainWidgetAnimation ->start();
        this ->show();//显示主界面
        this ->slot_ShowMusicPanel();
    }
}

//最小化
void Widget::slot_ShowMinSize()
{
    this ->showMinimized();
    musicListWidget ->showMinimized();
    musicDownload ->showMinimized();
}

//显示歌词已经锁定信息
void Widget::slot_ShowLrcLocked()
{
    trayIcon ->showMessage(tr("提示"), tr("你的桌面歌词已经锁定,点击播放器图标右键可以解锁"));
}

//显示歌词已经解锁信息
void Widget::slot_ShowLrcUnlocked()
{
    trayIcon ->showMessage(tr("提示"), tr("你的桌面歌词已经解锁"));
}

//解锁歌词
void Widget::slot_UnlockLrc()
{
    lrc ->unlockLrc();//解锁歌词
}

////定位到当前歌曲
//void Widget::locateCurrentMusic()
//{
//    int index = sources.indexOf(mediaObject ->currentSource());
//    playList ->selectRow(index);
//}

void Widget::slot_ShortCutsetDisable()//设置全局热键禁用/启用
{
	if (minMusicWidget ->isHidden())
	{
		//启用以下热键
		GlobalHotKey::showHideMainWidgetDisabled(false);
		GlobalHotKey::showDownloadDisabled(false);
		GlobalHotKey::showMusicListDisabled(false);
	}
	else
	{
		//禁用以下热键
		GlobalHotKey::showHideMainWidgetDisabled(true);
		GlobalHotKey::showDownloadDisabled(true);
		GlobalHotKey::showMusicListDisabled(true);
	}
}

//主界面鼠标右键点击事件
void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(closeAction);
    menu.addAction(minAction);
    menu.addAction(QIcon(":/images/minMainWidget.png"), tr("开启小界面"), this, SLOT(slot_OpenMinWidget()));
    menu.addSeparator();
    menu.addAction(openFileAction);
    menu.addAction(openMusicListAction);
    menu.addAction(openMusicDownloadAction);
    menu.addAction(openLrcAction);
    menu.addSeparator();
    menu.addAction(configAction);
	menu.addAction(aboutAction);
    menu.addAction(aboutQtAction);
    menu.exec(event ->globalPos());//globalPos()为当前鼠标的位置坐标
    //menu.exec(QCursor::pos());
    event ->accept();
}

//拖进事件
void Widget::dragEnterEvent(QDragEnterEvent *event)
{
    QList<QUrl> urls = event ->mimeData() ->urls();
    foreach (QUrl url, urls)
    {
        QString filePath = url.toLocalFile();
        QStringList fileList = filePath.split('.');
        QString kzName = fileList.at(1);
        if (kzName == "mp3" || kzName == "MP3" || kzName == "wav" || kzName == "WAV"
                || kzName == "wma" || kzName == "WMA" || kzName == "ogg" || kzName == "OGG")
        {
            event ->accept();
        }
        else
        {
            event ->ignore();
        }
    }
}

//放下事件
void Widget::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event ->mimeData() ->urls();
    if (urls.isEmpty())
    {
        return;
    }

    //获取当前媒体源列表的大小
    int index = sources.size();

    foreach (QUrl url, urls)
    {
        QString filePath = url.toLocalFile();
        Phonon::MediaSource source(filePath);//将每一个音乐加载成一个源
        sources.append(source);//将每一个源添加到媒体资源列表
    }

    if (!sources.isEmpty())
    {
        //如果媒体源列表不为空，则将新加入的第一个媒体源作为当前媒体源
        metaInformationResolver ->setCurrentSource(sources.at(index));
    }

    int static count = 0;
    ++count;
    if (count == 1 && readyReadDb == 0)//第一次打开文件并且没有从数据库中读取
    {
        mediaObject ->setCurrentSource(sources.at(0));
        mediaObject ->play();
    }
    event ->accept();
}

//重写paintEvent,添加背景图片
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap backgroundImage;
    backgroundImage.load(":/images/mainBg3.png");

    //先通过pix的方法获得图片的过滤掉透明的部分得到的图片，作为loginPanel的不规则边框
    this ->setMask(backgroundImage.mask());
    painter.drawPixmap(0, 0, 400, 212, backgroundImage);

	////正弦表
	//static const int sineTable[16] = { 0, 38, 71, 92, 100, 92, 71, 38,	0, -38, -71, -92, -100, -92, -71, -38};

	//QFontMetrics metrics(font());	//字体指标
	//int x = (430 - metrics.width(lrcText)) / 2;
	//int y = (250 + metrics.ascent() - metrics.descent()) / 2;//上升 - 降落
	//QColor color;

	//for (int i = 0; i < lrcText.size(); ++i)
	//{
	//	int index = (step + i) % 16;
	//	color.setHsv((15 - index) * 16, 255, 191);
	//	painter.setPen(color);
	//	painter.drawText(x, y - ((sineTable[index] * metrics.height()) / 400), QString(lrcText[i]));
	//	x += metrics.width(lrcText[i]);
	//}

    event ->accept();
}

//重写mousePressEvent和mouseMoveEvent实现窗体的移动
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event ->button() == Qt::LeftButton)
    {
        dragPosition = event ->globalPos() - frameGeometry().topLeft();
        event ->accept();
    }
}

//重写mousePressEvent和mouseMoveEvent实现窗体的移动
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (event ->buttons() == Qt::LeftButton)
    {
        this ->move(event ->globalPos() - dragPosition);//移动窗体
        musicListWidget ->move(frameGeometry().bottomLeft());//移动窗体的时候音乐播放列表跟着移动
        musicDownload ->move(frameGeometry().topRight());//移动窗体的时候音乐下载界面跟着移动
        event ->accept();
    }
}

//时间事件
//void Widget::timerEvent( QTimerEvent *event )
//{
//	if (event ->timerId() == baseTimer.timerId())
//	{
//		++step;
//		update();
//	}
//	else
//	{
//		QWidget::timerEvent(event);
//	}
//}

//检测设备的插入
//void Widget::slotDeviceAdded( QString str )
//{
//	QDBusInterface device("org.freedesktop.Hal", str, "org.freedesktop.Hal.Device", QDBusConnection::systemBus());
//}

//检查设备的拨出
//void Widget::slotDeviceRemoved( QString str )
//{
//
//}
