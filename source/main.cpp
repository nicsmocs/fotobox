/* main.cpp
 *
 * Copyright (c) 2016 Thomas Kais
 * Copyright (c) 2023 NicsMocs
 *
 * This file is subject to the terms and conditions defined in
 * file 'COPYING', which is part of this source code package.
 */
#include "preferences.h"

#include <QApplication>
#include <QBitmap>
#include <QLibraryInfo>
#include <QPixmap>
#include <QSplashScreen>
#include <QTranslator>

/*!
* \brief main
* \param argc argument count
* \param argv argument vector
* \return int EXIT CODE
*/
auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);

    //splash screen FotoBox logo
    QPixmap pixmap(QStringLiteral(":/resources/logo"));
    QSplashScreen splash(pixmap, Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
    //Linux: fix issue with transparent png
    splash.setMask(pixmap.mask());
    splash.show();

    //set application information
    QApplication::setOrganizationName(QStringLiteral("NicsMocs & Thomas Kais"));
    QApplication::setApplicationName(QStringLiteral("FotoBox"));
    QApplication::setApplicationVersion(QStringLiteral("1.6.0"));

    QTranslator qtTranslator;
    QTranslator appTranslator;
    //Qt Translation
    if (qtTranslator.load(QLocale(), QStringLiteral("qt"), QStringLiteral("_"),
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
                          QLibraryInfo::path(QLibraryInfo::TranslationsPath
#else
                          QLibraryInfo::location(QLibraryInfo::TranslationsPath
#endif
                                             ))) {
        QApplication::installTranslator(&qtTranslator);
    }
    //app Translation: German or English (=default language)
    bool result = false;
    if (QLocale::system().language() == QLocale::German) {
        result = appTranslator.load(QStringLiteral(":/resources/translation_de"));
    } else {
        result = appTranslator.load(QStringLiteral(":/resources/translation_en"));
    }
    if (result) {
        QApplication::installTranslator(&appTranslator);
    }

    //show preferences dialog and close splashscreen
    auto *dialog = new FotoBox::Preferences();
    splash.finish(dialog);
    dialog->show();

    return app.exec();
}
