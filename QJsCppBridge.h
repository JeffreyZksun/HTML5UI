
#pragma once

#include <QtCore/QObject>

class QWebFrame;
class QJsApiHandler;
class QJsApiProxy;

class QJsCppBridge : public QObject
{
	Q_OBJECT
public:
	QJsCppBridge(QWebFrame *pWebFrame);
	~QJsCppBridge();

public slots:
	void bridge_javaScriptWindowObjectCleared();
	void bridge_loadFinished(bool b);

private:
	QWebFrame*		m_pWebFrame;
	QJsApiHandler*	m_pJsApiHandler;
	QJsApiProxy*	m_pJsApiProxy;
};

