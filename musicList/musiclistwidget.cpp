#include "stdafx.h"
#include "musiclistwidget.h"


MusicListWidget::MusicListWidget(MusicList *playList, map<QString, int> *musicInfoMap, QWidget *parent)
    : m_playList(playList), m_musicInfoMap(musicInfoMap), m_parent(parent)
{
    //���ô��ڻ�������
    this ->resize(400, 450);//���ô����С
    this ->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);//ȥ������߿�
    this ->setAttribute(Qt::WA_TranslucentBackground);//���ñ���͸��
    this ->setWindowIcon(QIcon(":/images/CZPlayer.png"));//����logo
    this ->setWindowTitle(tr("�����б�"));

    //������
    searchLineEdit = new QLineEdit(this);
    searchLineEdit ->setObjectName(tr("searchLineEdit"));
    searchLineEdit ->setText(tr("�������֡�����"));
    searchLineEdit ->installEventFilter(this);
    //searchLineEdit ->setPlaceholderText(tr("�������֡�����"));

    //������ť
    searchButton = new QPushButton(this);
    searchButton ->setObjectName(tr("searchButton"));

    //����
    backButton = new QPushButton(this);
    backButton ->setObjectName(tr("backButton"));
    backButton ->setToolTip(tr("���������б�"));
    backButton ->setVisible(false);

    //���Ӹ���
    addMusicButton = new QPushButton(this);
    addMusicButton ->setObjectName(tr("addMusicButton"));
    addMusicButton ->setToolTip(tr("���Ӹ���"));

    //��λ����
    localeButton = new QPushButton(this);
    localeButton ->setObjectName(tr("localeButton"));
    localeButton ->setToolTip(tr("��λ��ǰ���Ÿ���"));

    //ɾ����ǰ����
    delMusicButton = new QPushButton(this);
    delMusicButton ->setObjectName(tr("delMusicButton"));
    delMusicButton ->setToolTip(tr("ɾ����ǰ����"));

    //��������
    findButton = new QPushButton(this);
    findButton ->setObjectName(tr("findButton"));
    findButton ->setToolTip(tr("��������"));

	//���Ӹ���
	addMusicAction = new QAction(this);
	addMusicAction ->setIcon(QIcon(":/images/addMusic.png"));
	addMusicAction ->setText(tr("���Ӹ���"));

	//���Ӳ����б�
	addMusicListAction = new QAction(this);
	addMusicListAction ->setIcon(QIcon(":/images/addMusicList.png"));
	addMusicListAction ->setText(tr("���벥���б�"));

    //��ʱ��
    timer = new QTimer(this);
    timer ->start(1000);

    QSpacerItem *topItem = new QSpacerItem(380, 37, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSpacerItem *bottomItem = new QSpacerItem(380, 30, QSizePolicy::Fixed, QSizePolicy::Fixed);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout ->addItem(topItem);
    mainLayout ->addWidget(m_playList);
    mainLayout ->addItem(bottomItem);
    this ->setLayout(mainLayout);

    searchLineEdit ->setGeometry(27, 7, 250, 30);
    searchButton ->setGeometry(287, 9, 90, 30);
    backButton ->setGeometry(257, 15, 15, 14);
//    m_playList ->setGeometry(10, 37, 380, 360);
    addMusicButton ->setGeometry(60, 417, 25, 25);
    localeButton ->setGeometry(145, 417, 25, 25);
    delMusicButton ->setGeometry(230, 417, 25, 25);
    findButton ->setGeometry(315, 417, 25, 25);

    //�ź����
    connect(addMusicButton, SIGNAL(clicked()), this, SLOT(slot_OnClickedAddMusic()));			//���Ӹ���
    connect(localeButton, SIGNAL(clicked()), m_playList, SLOT(slot_LocateCurrentMusic()));		//��λ��ǰ���Ÿ���
    connect(delMusicButton, SIGNAL(clicked()), m_playList, SLOT(slot_DelCurrentMusic()));		//ɾ����ǰ����
    connect(searchButton, SIGNAL(clicked()), this, SLOT(slot_SearchMusic()));					//��������
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_LineEditFocus()));						//�����۽�
    connect(backButton, SIGNAL(clicked()), this, SLOT(slot_BackMusicList()));					//���������б�
	connect(addMusicAction, SIGNAL(triggered()), this, SLOT(slot_AddMusic()));					//���Ӹ���
	connect(addMusicListAction, SIGNAL(triggered()), this, SLOT(slot_AddMusicList()));			//���Ӳ����б�
}

MusicListWidget::~MusicListWidget()
{
}

//���Ӹ���
void MusicListWidget::slot_OnClickedAddMusic()
{
	QMenu menu;
	menu.addAction(addMusicAction);
	menu.addAction(addMusicListAction);
	menu.exec(QCursor::pos());
}

//�����۽�
void MusicListWidget::slot_LineEditFocus()
{
    if ("" == searchLineEdit ->text() && !searchLineEdit ->hasFocus())
    {
        searchLineEdit ->setText(tr("�������֡�����"));
        backButton ->setVisible(false);
    }
}

//���������б�
void MusicListWidget::slot_BackMusicList()
{
    for (int index = 0; index < m_playList ->rowCount(); ++index)
    {
        m_playList ->showRow(index);
    }
}

//��������
void MusicListWidget::slot_SearchMusic()
{
    QString str = searchLineEdit ->text();
    if ("�������֡�����" == str)
    {
        return;
    }
    map<QString, int>::iterator begin = m_musicInfoMap ->begin();
    map<QString, int>::iterator end = m_musicInfoMap ->end();
    while (begin != end)
    {
        if (!(begin ->first).contains(str))
        {
            m_playList ->hideRow(begin ->second);
        }
        if ((begin ->first).contains(str))
        {
            m_playList ->showRow(begin ->second);
        }
        ++begin;
    }
}

//���Ӹ���
void MusicListWidget::slot_AddMusic()
{
    emit sig_AddMusic();
}

//���Ӳ����б�
void MusicListWidget::slot_AddMusicList()
{
	emit sig_AddMusicList();
}

//��дpaintEvent,���ӱ���ͼƬ
void MusicListWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap backgroundImage;
    backgroundImage.load(":/images/musicList.png");

    //��ͨ��pix�ķ������ͼƬ�Ĺ��˵�͸���Ĳ��ֵõ���ͼƬ����ΪloginPanel�Ĳ�����߿�
    this ->setMask(backgroundImage.mask());
    painter.drawPixmap(0, 0, 400, 450, backgroundImage);
    event ->accept();
}

//�¼�������
bool MusicListWidget::eventFilter(QObject *target, QEvent *event)
{
    if (target == searchLineEdit)
    {
        if (event ->type() == QEvent::KeyPress)
        {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            if (keyEvent ->key() == Qt::Key_Return)
            {
                searchButton ->click();//ѡ�����ذ�ť
                return true;
            }
        }

        if (event ->type() == QEvent::MouseButtonPress)
        {
            if ("�������֡�����" == searchLineEdit ->text())
            {
                searchLineEdit ->setText(tr(""));
                backButton ->setVisible(true);
            }
            return true;
        }
    }

    return QWidget::eventFilter(target, event);
}
