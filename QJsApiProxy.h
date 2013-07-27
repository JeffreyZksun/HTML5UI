#pragma once

#include <QtCore/QObject>

class QWebFrame;

/// The call from C++ code to Java script is via this class.
/// This class will delegate the call the Java script function onEventStub.
/// In the html page, the Java script function "function onEventStub(para) { return "NO_IMP";}" should be implemented
/// to response the call.
class QJsApiProxy : QObject
{
	Q_OBJECT

public:
	QJsApiProxy(QWebFrame *pWebFrame);

	QString onEvent(const QString &para);

private:
	QWebFrame*		m_pWebFrame;
};
