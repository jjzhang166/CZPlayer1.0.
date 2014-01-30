#ifndef MUSICLISTSAVEFORMATENTITY_H
#define MUSICLISTSAVEFORMATENTITY_H

#include "head.h"
#include "Entity.h"

class MusicListSaveFormatEntity : public Entity
{
public:
	MusicListSaveFormatEntity();
	MusicListSaveFormatEntity(string strTitle, string strTime, string strFilePath);
	~MusicListSaveFormatEntity();

	string getTitle() const { return m_strTitle; }
	void setTitle(const string &val) { m_strTitle = val; }

	string getTime() const { return m_strTime; }
	void setTime(const string &val) { m_strTime = val; }

	string getFilePath() const { return m_strFilePath; }
	void setFilePath(const string &val) { m_strFilePath = val; }

private:
	string m_strTitle;
	string m_strTime;
	string m_strFilePath;
};

#endif //MUSICLISTSAVEFORMATENTITY_H