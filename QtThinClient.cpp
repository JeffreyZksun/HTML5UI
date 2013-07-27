
/************************************************************************/

/// To make this project build successfully, the Qt 4.8.2 should be installed to C:\Qt\
/// The expected location of qmake.exe is: C:\Qt\4.8.2\bin\qmake.exe

/************************************************************************/
#include "stdafx.h"

#include <QtGUI/QApplication>
#include <QtWebkit/QWebView>
#include <QtWebkit/QWebFrame>
#include <QtCOre/QFileInfo>

#include "QJsCppBridge.h"

int _tmain(int argc, char* argv[])
{
	// Initialize Qt.
	QApplication app( argc, argv );

	//QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

	QWebView mWebView;
	{
		mWebView.setGeometry(50,100,400,200);
		QPalette palette = mWebView.palette();
		palette.setBrush(QPalette::Base, Qt::transparent);
		mWebView.page()->setPalette(palette);
		mWebView.setAttribute(Qt::WA_OpaquePaintEvent, false);
	}

	QWebFrame *frame = mWebView.page()->mainFrame();

	QJsCppBridge bridge(frame);

	// Load html page
	{
		QString path = QFileInfo(QCoreApplication::applicationFilePath()).absolutePath();
		QString htmlPage = "file:///" + path + "/Html/index1.html";
		mWebView.load(QUrl(htmlPage));
	}

	mWebView.show();
	
	// Run the message loop.
	app.exec();


	return 0;

}

