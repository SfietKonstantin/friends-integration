/*
 * Copyright (C) 2013 Jolla Ltd. <chris.adams@jollamobile.com>
 *
 * You may use this file under the terms of the BSD license as follows:
 *
 * "Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Nemo Mobile nor the names of its contributors
 *     may be used to endorse or promote products derived from this
 *     software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 */

#include <QtGlobal>
#include <QtQml>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>
#include <QGuiApplication>
#include "friendspostmodel.h"
#include "friendspostinterface.h"
#include "synchelper.h"

class AppTranslator: public QTranslator
{
    Q_OBJECT
public:
    AppTranslator(QObject *parent)
        : QTranslator(parent)
    {
        qApp->installTranslator(this);
    }

    virtual ~AppTranslator()
    {
        qApp->removeTranslator(this);
    }
};

static const char *REASON = "Cannot be created";

class Q_DECL_EXPORT FriendsIntegrationPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.SfietKonstantin.friends.integration.eventsview")
public:
    virtual ~FriendsIntegrationPlugin() { }

    void initializeEngine(QQmlEngine *engine, const char *uri)
    {
        Q_ASSERT(uri == QLatin1String("org.SfietKonstantin.friends.integration.eventsview"));
        Q_UNUSED(uri)
//        AppTranslator *engineeringEnglish = new AppTranslator(engine);
//        AppTranslator *translator = new AppTranslator(engine);
//        engineeringEnglish->load("friends-engineering-english", "/usr/share/harbour-friends/translations/");
//        translator->load(QLocale(), "friends", "_", "/usr/share/harbour-friends/translations/");
    }

    void registerTypes(const char *uri)
    {

        Q_ASSERT(uri == QLatin1String("org.SfietKonstantin.friends.integration.eventsview"));
        qmlRegisterUncreatableType<FriendsObjectReferenceInterface>(uri, 1, 0, "FriendsObjectReferenceInterface", REASON);
        qmlRegisterUncreatableType<FriendsNameTagInterface>(uri, 1, 0, "FriendsNameTagInterface", REASON);
        qmlRegisterUncreatableType<FriendsPostInterface>(uri, 1, 0, "FriendsPostInterface", REASON);
        qmlRegisterType<FriendsPostModel>(uri, 1, 0, "FriendsPostModel");
        qmlRegisterType<SyncHelper>(uri, 1, 0, "SyncHelper");
    }
};

#include "plugin.moc"
