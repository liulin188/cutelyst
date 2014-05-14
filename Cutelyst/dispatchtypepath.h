/*
 * Copyright (C) 2013 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef CUTELYST_DISPATCHTYPEPATH_H
#define CUTELYST_DISPATCHTYPEPATH_H

#include "dispatchtype.h"
#include "action.h"

#include <QMap>

namespace Cutelyst {

class DispatchTypePath : public DispatchType
{
    Q_OBJECT
public:
    explicit DispatchTypePath(QObject *parent = 0);

    virtual void list() const;

    virtual bool match(Context *ctx, const QString &path) const;

    virtual bool registerAction(Action *action);

    virtual QString uriForAction(Action *action, const QStringList &captures) const;

private:
    bool registerPath(const QString &path, Action *action);

    QHash<QString, ActionList> m_paths;
};

}

#endif // DispatchTypePath_H