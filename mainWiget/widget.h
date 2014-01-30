#ifndef WIDGET_H
#define WIDGET_H

#include "musiclist.h"
#include "musiclrc.h"
#include "musicdownload.h"
#include "albumthread.h"
#include "lrcthread.h"
#include "HotplugWatcherThread.h"
#include "minmusicwidget.h"
#include "musiclistwidget.h"
#include "configdialog.h"
#include "AboutPanel.h"
#include "globalhotkey.h"
#include "head.h"
//#include <QtDBus/QDBusConnection>

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    Widget();
    ~Widget();

public:
    int getMusicListShow() const;
    void setMusicListShow(int value);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
	//void timerEvent(QTimerEvent *event);

signals:
    void sig_ShowMainWidget();																	//显示主界面

private slots:
    void slot_UpdateTime(qint64 time);														//更新时间和歌词
    void slot_OpenMinWidget();
    void slot_OpenFile();																	//打开音乐文件
	void slot_AddMusicList();																//添加播放列表
    void slot_OpenMusicList();																//打开音乐播放列表
    void slot_OpenMusicLrc();																//打开歌词
    void slot_OpenMusicDownload();															//打开下载歌曲界面
    void slot_HideMusicDownload();															//隐藏下载歌曲界面
    void slot_HideMusicList();																//隐藏音乐播放器列表
    void slot_HideMainWidget();																//隐藏主界面
    void slot_ShowMusicPanel();																//显示主界面
    void slot_ConfigCZPlayer();																//设置
	void slot_AboutCZPlayer();																//关于CZPlayer
    void slot_AboutQt();																	//关于Qt
    void slot_SetPaused();																	//暂停
    void slot_SetStop();																	//停止
    void slot_SetPre();																		//上一首
    void slot_SetNext();																	//下一首
    void slot_StateChanged(Phonon::State newState, Phonon::State /*oldState*/);				//播放状态改变
    void slot_RowChanged(const Phonon::MediaSource &source);								//选中当前播放媒体源的行
    void slot_TableDoubleClicked(int row, int /*column*/);									//双击媒体库选中播放该音乐
    void slot_ClearSources();																//清空源
    void slot_DelSelectSource(int row, QString title);										//删除选中源和数据库相应歌曲
    void slot_AboutMusicFinish();															//播放结束时调用
    void slot_MetaStateChanged(Phonon::State newState, Phonon::State /*oldState*/);			//媒体源改变时，添加新的源
    void slot_TrayIconActivated(QSystemTrayIcon::ActivationReason activationReason);		//系统托盘激活处理
    void slot_ShowMinSize();																//最小化
    void slot_MinToTray();																	//最小化到推盘
    void slot_ShowLrcLocked();																//显示歌词已经锁定信息
    void slot_ShowLrcUnlocked();															//显示歌词已经解锁信息
    void slot_UnlockLrc();																	//解锁歌词
    void slot_CloseAllProgress();															//退出程序
    void slot_TimeOut();																	//定时器
	void slot_ResolveLrc();																	//解析歌词
	void slot_ShortCutsetDisable();															//设置全局热键禁用/启用
    void slot_ConfigOptions();																//选项设置
    void slot_ShowHideMainWidget();															//显示/隐藏主界面
    void slot_MinMainWidget();																//迷你模式/正常窗口
    void slot_OpenMusicfile();																//打开音乐文件
    void slot_ShowDownload();																//显示/隐藏下载列表
    void slot_ShowMusicList();																//显示/隐藏歌曲列表
    void slot_ShowLrc();																	//显示/隐藏桌面歌词
    void slot_PlayPause();																	//播放/暂停
    void slot_Last();																		//上一首
    void slot_Next();																		//下一首

	//void slotDeviceAdded(QString str);//检测设备的插入
	//void slotDeviceRemoved(QString str);//检查设备的拨出

private:
    void resolveLrc(const QString &sourceFileName);											//解析歌词
    void readFromDb();																		//从数据库中读出数据显示到音乐里列表中
    void updateMap();																		//更新map

private:
    //显示变量（0：关闭，1：开启）
    int musicListShowFlag;
    int musicDownloadShowFlag;

    QPoint dragPosition;
    QTimer *timer;
	QTimer *shortCutIimer;

    MinMusicWidget *minMusicWidget;							//迷你播放界面
    MusicList *playList;									//播放列表
    MusicListWidget *musicListWidget;
    MusicLrc *lrc;											//歌词
    MusicDownload *musicDownload;							//歌曲下载
    ConfigDialog *configDialog;								//设置界面
	AboutPanel *aboutPanel;									//关于CZPlayer
    GlobalHotKey *globalHotKey;								//全局热键
	HotplugWatcherThread *hotpugWatcherThread;				//设备监听

    QMap<qint64, QString> lrcMap;
    map<QString, int> musicInfoMap;

    Phonon::MediaObject *mediaObject;						//声明媒体对象
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaObject *metaInformationResolver;			//源信息解析
    Phonon::AudioOutput *metaInformationAudioOutput;
    Phonon::SeekSlider *seekSlider;							//播放控制条
    Phonon::VolumeSlider *volumeSlider;						//音量调节条
    QList<Phonon::MediaSource> sources;						//存放媒体资源

    QLabel *albumImage;
    QLabel *timeLabel;
    QLabel *InfoLabel;
	QLabel *lrcLabel;

    QAction *closeAction;
    QAction *pauseAction;
    QAction *stopAction;
    QAction *lastAction;
    QAction *nextAction;
    QAction *minAction;
    QAction *quitAction;
    QAction *unlockLrcAction;
    QAction *openFileAction;
    QAction *openMusicListAction;
    QAction *openMusicDownloadAction;
    QAction *openLrcAction;
    QAction *configAction;
	QAction *aboutAction;
    QAction *aboutQtAction;

    QMenu *trayMenu;										//系统推盘菜单
    QSystemTrayIcon *trayIcon;								//系统托盘图标
    QMovie *movie;

    QPushButton *playButton;
    QPushButton *endButton;
    QPushButton *preButton;
    QPushButton *nextButton;
    QPushButton *openFileButton;
    QPushButton *musicListButton;
    QPushButton *lrcButton;
    QPushButton *showButton;

    QString m_musicName;
    QString m_musicArtist;
    QString m_lrcFileName;
    QString m_title;
    QString m_artist;
    int readyReadDb;

	//QBasicTimer baseTimer;
	//QString lrcText;
	//int step;
};

#endif // WIDGET_H
