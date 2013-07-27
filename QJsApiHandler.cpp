#include "stdafx.h"

#include "QJsApiHandler.h"

#include "debug/moc_QJsApiHandler.cpp"

void QJsApiHandler::request(QString json)
{
	QString result = onEvent(json);
	emit success(result);
}

QString QJsApiHandler::onEvent(const QString &json)
{
	return "OK, " + json;
}