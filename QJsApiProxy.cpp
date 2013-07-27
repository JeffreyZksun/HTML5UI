#include "stdafx.h"
#include "QJsApiProxy.h"

#include <QtWebkit/QWebFrame>
#include "debug/moc_QJsApiProxy.cpp"

QJsApiProxy::QJsApiProxy(QWebFrame *pWebFrame) : m_pWebFrame(pWebFrame)
{

}

QString QJsApiProxy::onEvent(const QString &para)
{
	if(m_pWebFrame)
	{
		static QString functionSignature = "onEventStub(\"%1\")";
		QString functionInvoke = functionSignature.arg(para);
		QVariant result = m_pWebFrame->evaluateJavaScript(functionInvoke);

		return result.toString(); 
	}

	return "ERROR_DISCONNECTED";
}