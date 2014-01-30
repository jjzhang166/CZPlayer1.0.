#ifndef MINMUSICWIDGET_H
#define MINMUSICWIDGET_H

#include "head.h"

class MinMusicWidget : public QWidget
{
    Q_OBJECT

public:
    MinMusicWidget(Phonon::MediaObject *mediaObject,
                   QList<Phonon::MediaSource> *sources,
                   QWidget *parent = 0);
    ~MinMusicWidget();

    QPushButton *minPlayButton;
    QPushButton *minPauseButton;
    QPushButton *minStopButton;
    QPushButton *minNextButton;
    QPushButton *minLastButton;
    QPushButton *minOpenFileButton;
    QAction *minMusicLrcAction;

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void contextMenuEvent(QContextMenuEvent *event);

signals:
    void sig_MinPlay();
    void sig_MinPause();
    void sig_MinStop();
    void sig_MinNext();
    void sig_MinLast();
    void sig_OpenFileButtonClicked();
    void sig_MusicLrc();
    void sig_ShowMusicPanel();

private slots:
    void slot_SetPlay();//播放
    void slot_SetPaused();//暂停
    void slot_SetStop();//停止
    void slot_SetPre();//上一首
    void slot_SetNext();//下一首
    void slot_OpenFile();//打开音乐文件
    void slot_OpenMainWidget();//打开主界面
    void slot_OpenMusicLrc();//桌面歌词
    void slot_HideMinWidget();//隐藏小界面

private:
    QWidget *m_parent;
    QPoint dragPosition;

    Phonon::MediaObject *m_mediaObject;//声明媒体对象
    QList<Phonon::MediaSource> *m_sources;//存放媒体资源
};

#endif // MINMUSICWIDGET_H
