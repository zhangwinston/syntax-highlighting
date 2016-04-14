/*
    Copyright (C) 2016 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "syntaxrepository.h"
#include "syntaxdefinition.h"

#include <QDebug>
#include <QDirIterator>

using namespace KateSyntax;

SyntaxRepository::SyntaxRepository()
{
    load();
}

SyntaxRepository::~SyntaxRepository()
{
}

void SyntaxRepository::load()
{
    QDirIterator it(QStringLiteral(":/kate-syntax"));
    while (it.hasNext()) {
        auto def = new SyntaxDefinition;
        if (def->load(it.next()))
            m_defs.push_back(def);
    }

    qDebug() << "Found" << m_defs.size() << "syntax definitions.";
}
