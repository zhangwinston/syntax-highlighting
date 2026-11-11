/*
 *  SPDX-FileCopyrightText: 2026 Kai Uwe Broulik <kde@broulik.de>
 *
 *  SPDX-License-Identifier: MIT
 */

#ifndef THEMEPREVIEWICON_P_H
#define THEMEPREVIEWICON_P_H

#include <QIconEngine>

#include "theme.h"

namespace KSyntaxHighlighting
{

class ThemePreviewIconEngine : public QIconEngine
{
public:
    explicit ThemePreviewIconEngine(const KSyntaxHighlighting::Theme &theme);

    void paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state) override;
    QIconEngine *clone() const override;

    QSize actualSize(const QSize &size, QIcon::Mode mode, QIcon::State state) override;
    QPixmap pixmap(const QSize &size, QIcon::Mode mode, QIcon::State state) override;
#if QT_VERSION >= QT_VERSION_CHECK(6, 8, 0)
    QPixmap scaledPixmap(const QSize &size, QIcon::Mode mode, QIcon::State state, qreal scale) override;
#else
    // QIconEngine::scaledPixmap only became virtual in Qt 6.8; keep a plain member on Qt 5
    QPixmap scaledPixmap(const QSize &size, QIcon::Mode mode, QIcon::State state, qreal scale);
#endif

private:
    void paint(QPainter *painter, const QRect &rect, QIcon::Mode mode, QIcon::State state, bool includeFrame);

    KSyntaxHighlighting::Theme m_theme;
};

} // namespace KSyntaxHighlighting

#endif // THEMEPREVIEWICON_P_H
