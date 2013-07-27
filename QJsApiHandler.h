#pragma once

#include <QtCore/QObject>

/// The call from Java script to C++ code is via this class.
/// The instance of this class is exposed as the global object in Java script.
/// In Java script, the statement var result = jsHandler.onEvent("parameter data"); 
/// can be used to call the C++ code.
class QJsApiHandler : public QObject
{
	Q_OBJECT

		// 1. Get the result from call back.
		// Define the jQuery-like signals and slots. 
signals:
	void success(QString json);
	void error(QString json);
public slots:
	void request(QString json);

	// 2. Get the result from return value.
public slots:
	// Exception: The return value can be accessed in JS.
	QString onEvent(const QString &json);
};
