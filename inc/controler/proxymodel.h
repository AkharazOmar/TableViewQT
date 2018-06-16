/*
 * Copyright 2018 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>

namespace eventManager {
namespace controller {

/**
 * @todo write docs
 */
class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    ProxyModel(QObject * parent=Q_NULLPTR);

    /**
     * Copy Constructor
     *
     * @param other TODO
     */
    ProxyModel ( const ProxyModel& other ) =  delete;

    /**
     * Destructor
     */
    ~ProxyModel()  noexcept;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    ProxyModel& operator= ( const ProxyModel& other )=  delete;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator== ( const ProxyModel& other ) const = delete;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!= ( const ProxyModel& other ) const = delete;

};

}
}
#endif // PROXYMODEL_H
