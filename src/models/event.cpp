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

#include "models/event.h"

#include <QSharedData>
namespace eventManager  {
namespace model {

class EventData : public QSharedData
{
public:
    
    EventData() = default;
    EventData(const EventData &orig) = default;
    EventData & operator =(const EventData& cpEventD) {
        if (this != &cpEventD) {
            //QSharedData(cpEventD);
            oidEvent_ = cpEventD.oidEvent_;
            standardAttributes_ = cpEventD.standardAttributes_;
            specificAttributes_ = cpEventD.specificAttributes_;
        }

        return *this;
    }

    EventData(EventData &&orig) noexcept:
        oidEvent_(std::move(orig.oidEvent_)),
        standardAttributes_(std::move(orig.standardAttributes_)),
        specificAttributes_(std::move(orig.specificAttributes_))
    {

    }

    EventData &operator=(EventData &&orig) noexcept
    {
        if (this == &orig) {
            oidEvent_ = std::move(orig.oidEvent_);
            standardAttributes_ = std::move(orig.standardAttributes_);
            specificAttributes_ = std::move(orig.specificAttributes_);
        }
        return *this;
    }

    ~EventData() = default;
    
    QString oidEvent_;
    QHash<QString, QVariant> standardAttributes_;
    QHash<QString, QVariant> specificAttributes_;
};

const QStringList Event::STANDARD_ATTRIBUTE = {
        "first",
        "second",
        "tree"
    };

Event::Event()
    : d ( new EventData() ) { }

Event::Event ( const Event& other )
    : d ( other.d )
{
}
Event::~Event() noexcept = default;

Event& Event::operator= ( const Event& other )
{
    if (this != &other) {
        d = other.d;
    }
    return *this;
}

bool Event::operator== ( const Event& other ) const
{
    return other.d->oidEvent_ == d->oidEvent_;
}

bool Event::operator!= ( const Event& other ) const
{
    return other.d->oidEvent_ != d->oidEvent_;
}

const QString &Event::oid() const noexcept
{
    return d->oidEvent_;
}

void Event::setStandardAttribute ( const QString& name, const QVariant& value ) noexcept
{
    d->standardAttributes_.insert(name, value);
}

void Event::setSpecificAttribute ( const QString& name, const QVariant& value ) noexcept
{
    d->specificAttributes_.insert(name, value);
}

const QVariant &Event::standardAttribute(const QString &name) const noexcept
{
    return d->standardAttributes_.find(name).value();
}
 
const QVariant &Event::specificAttribute(const QString &name) const noexcept
{
    return d->specificAttributes_.find(name).value();
}
}
}
