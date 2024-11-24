//
// Created by Alexandru Pestritu on 24.11.2024.
//

#ifndef FONTMANAGER_H
#define FONTMANAGER_H
#include <QFontDatabase>

inline void registerFonts() {
    QFontDatabase::addApplicationFont(":/fonts/Halo_Dek.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Black.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-BlackItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-BoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-ExtraBold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-ExtraBoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-ExtraLight.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-ExtraLightItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Italic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Light.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-LightItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Medium.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-MediumItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-SemiBold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-SemiBoldItalic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-Thin.ttf");
    QFontDatabase::addApplicationFont(":/fonts/poppins/Poppins-ThinItalic.ttf");
}

#endif //FONTMANAGER_H
