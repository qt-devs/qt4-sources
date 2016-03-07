/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(3D_CANVAS)

#include "JSCanvasIntArray.h"

#include "CanvasIntArray.h"
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCanvasIntArray);

/* Hash table for prototype */

static const HashTableValue JSCanvasIntArrayPrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCanvasIntArrayPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSCanvasIntArrayPrototypeTableValues, 0 };
#else
    { 1, 0, JSCanvasIntArrayPrototypeTableValues, 0 };
#endif

const ClassInfo JSCanvasIntArrayPrototype::s_info = { "CanvasIntArrayPrototype", 0, &JSCanvasIntArrayPrototypeTable, 0 };

JSObject* JSCanvasIntArrayPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCanvasIntArray>(exec, globalObject);
}

const ClassInfo JSCanvasIntArray::s_info = { "CanvasIntArray", &JSCanvasArray::s_info, 0, 0 };

JSCanvasIntArray::JSCanvasIntArray(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<CanvasIntArray> impl)
    : JSCanvasArray(structure, globalObject, impl)
{
}

JSObject* JSCanvasIntArray::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCanvasIntArrayPrototype(JSCanvasIntArrayPrototype::createStructure(JSCanvasArrayPrototype::self(exec, globalObject)));
}

bool JSCanvasIntArray::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<CanvasIntArray*>(impl())->length()) {
        slot.setValue(getByIndex(exec, index));
        return true;
    }
    return Base::getOwnPropertySlot(exec, propertyName, slot);
}

bool JSCanvasIntArray::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<CanvasIntArray*>(impl())->length()) {
        descriptor.setDescriptor(getByIndex(exec, index), DontDelete);
        return true;
    }
    return Base::getOwnPropertyDescriptor(exec, propertyName, descriptor);
}

bool JSCanvasIntArray::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<CanvasIntArray*>(impl())->length()) {
        slot.setValue(getByIndex(exec, propertyName));
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

void JSCanvasIntArray::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok) {
        indexSetter(exec, index, value);
        return;
    }
    Base::put(exec, propertyName, value, slot);
}

void JSCanvasIntArray::put(ExecState* exec, unsigned propertyName, JSValue value)
{
    indexSetter(exec, propertyName, value);
    return;
}

void JSCanvasIntArray::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames)
{
    for (unsigned i = 0; i < static_cast<CanvasIntArray*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames);
}


JSValue JSCanvasIntArray::getByIndex(ExecState* exec, unsigned index)
{
    return jsNumber(exec, static_cast<CanvasIntArray*>(impl())->item(index));
}
CanvasIntArray* toCanvasIntArray(JSC::JSValue value)
{
    return value.inherits(&JSCanvasIntArray::s_info) ? static_cast<JSCanvasIntArray*>(asObject(value))->impl() : 0;
}

}

#endif // ENABLE(3D_CANVAS)
