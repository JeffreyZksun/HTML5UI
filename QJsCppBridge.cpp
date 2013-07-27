#include "stdafx.h"

#include <QtWebkit/QWebFrame>
#include "QJsCppBridge.h"
#include "QJsApiHandler.h"
#include "QJsApiProxy.h"

#include "debug/moc_QJsCppBridge.cpp"

QJsCppBridge::QJsCppBridge(QWebFrame *pWebFrame) : m_pWebFrame(pWebFrame)
{
	if(m_pWebFrame)
	{
		// Listen to the javaScriptWindowObjectCleared signal. 
		// This step is important because WebKit is going to clear all the JavaScript objects when loading a new page, 
		// so you need to add back the bridge every time:
		QObject::connect(m_pWebFrame, SIGNAL(javaScriptWindowObjectCleared()), this, SLOT(bridge_javaScriptWindowObjectCleared()));

		QObject::connect(m_pWebFrame, SIGNAL(loadFinished(bool)), this, SLOT(bridge_loadFinished(bool)));
	}

	m_pJsApiHandler = new QJsApiHandler();
	m_pJsApiProxy = new QJsApiProxy(pWebFrame);
}

QJsCppBridge::~QJsCppBridge()
{
	m_pWebFrame = NULL;
	if(m_pJsApiHandler)
	{
		delete m_pJsApiHandler;
		m_pJsApiHandler = NULL;
	}

	if(m_pJsApiProxy)
	{
		delete m_pJsApiProxy;
		m_pJsApiProxy = NULL;
	}
}

// The jsHandler is exposed as a global object in the Java script.
// It can be used as var result = jsHandler.onEvent("parameter data");
void QJsCppBridge::bridge_javaScriptWindowObjectCleared() 
{
	if(m_pWebFrame)
	{
		m_pWebFrame->addToJavaScriptWindowObject("jsHandler", m_pJsApiHandler);
	}
}

void QJsCppBridge::bridge_loadFinished(bool b)
{
	if(m_pJsApiProxy)
	{
		QString result = m_pJsApiProxy->onEvent("Initialization completes!");
	}
}

