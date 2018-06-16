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

#ifndef EVENT_H
#define EVENT_H

#include <QVariant>
#include <QString>
#include <QStringList>
#include <QSharedDataPointer>
namespace eventManager  {
namespace model {


class EventData;

/**
 * @todo write docs
 */
class Event
{
public:
    static const QStringList STANDARD_ATTRIBUTE;
    /**
     * Default constructor
     */
    Event();

    /**
     * Copy Constructor
     *
     * @param other TODO
     */
    Event ( const Event& other );

    /**
     * Destructor
     */
    ~Event();

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    Event& operator= ( const Event& other );

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator== ( const Event& other ) const;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    bool operator!= ( const Event& other ) const;

    const QString &oid() const noexcept;

    /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    void setStandardAttribute ( const QString& name, const QVariant& value ) noexcept;

       /**
     * @todo write docs
     *
     * @param other TODO
     * @return TODO
     */
    void setSpecificAttribute ( const QString& name, const QVariant& value ) noexcept;

    const QVariant &standardAttribute(const QString &name) const noexcept;

    const QVariant &specificAttribute(const QString &name) const noexcept;
    
private:
    QSharedDataPointer<EventData> d;
};

}
}
Q_DECLARE_METATYPE(eventManager::model::Event)
#endif // EVENT_H
