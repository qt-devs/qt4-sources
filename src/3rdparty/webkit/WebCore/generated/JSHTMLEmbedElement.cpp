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
#include "JSHTMLEmbedElement.h"

#include "AtomicString.h"
#include "HTMLEmbedElement.h"
#include "HTMLNames.h"
#include "JSDOMBinding.h"
#include "JSHTMLEmbedElementCustom.h"
#include "JSSVGDocument.h"
#include "KURL.h"
#include "SVGDocument.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSHTMLEmbedElement);

/* Hash table */

static const HashTableValue JSHTMLEmbedElementTableValues[8] =
{
    { "align", DontDelete, (intptr_t)jsHTMLEmbedElementAlign, (intptr_t)setJSHTMLEmbedElementAlign },
    { "height", DontDelete, (intptr_t)jsHTMLEmbedElementHeight, (intptr_t)setJSHTMLEmbedElementHeight },
    { "name", DontDelete, (intptr_t)jsHTMLEmbedElementName, (intptr_t)setJSHTMLEmbedElementName },
    { "src", DontDelete, (intptr_t)jsHTMLEmbedElementSrc, (intptr_t)setJSHTMLEmbedElementSrc },
    { "type", DontDelete, (intptr_t)jsHTMLEmbedElementType, (intptr_t)setJSHTMLEmbedElementType },
    { "width", DontDelete, (intptr_t)jsHTMLEmbedElementWidth, (intptr_t)setJSHTMLEmbedElementWidth },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsHTMLEmbedElementConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLEmbedElementTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 16383, JSHTMLEmbedElementTableValues, 0 };
#else
    { 19, 15, JSHTMLEmbedElementTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSHTMLEmbedElementConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLEmbedElementConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLEmbedElementConstructorTableValues, 0 };
#else
    { 1, 0, JSHTMLEmbedElementConstructorTableValues, 0 };
#endif

class JSHTMLEmbedElementConstructor : public DOMConstructorObject {
public:
    JSHTMLEmbedElementConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSHTMLEmbedElementConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSHTMLEmbedElementPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSHTMLEmbedElementConstructor::s_info = { "HTMLEmbedElementConstructor", 0, &JSHTMLEmbedElementConstructorTable, 0 };

bool JSHTMLEmbedElementConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSHTMLEmbedElementConstructor, DOMObject>(exec, &JSHTMLEmbedElementConstructorTable, this, propertyName, slot);
}

bool JSHTMLEmbedElementConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSHTMLEmbedElementConstructor, DOMObject>(exec, &JSHTMLEmbedElementConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSHTMLEmbedElementPrototypeTableValues[2] =
{
    { "getSVGDocument", DontDelete|Function, (intptr_t)jsHTMLEmbedElementPrototypeFunctionGetSVGDocument, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSHTMLEmbedElementPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSHTMLEmbedElementPrototypeTableValues, 0 };
#else
    { 2, 1, JSHTMLEmbedElementPrototypeTableValues, 0 };
#endif

const ClassInfo JSHTMLEmbedElementPrototype::s_info = { "HTMLEmbedElementPrototype", 0, &JSHTMLEmbedElementPrototypeTable, 0 };

JSObject* JSHTMLEmbedElementPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSHTMLEmbedElement>(exec, globalObject);
}

bool JSHTMLEmbedElementPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSHTMLEmbedElementPrototypeTable, this, propertyName, slot);
}

bool JSHTMLEmbedElementPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSHTMLEmbedElementPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSHTMLEmbedElement::s_info = { "HTMLEmbedElement", &JSHTMLElement::s_info, &JSHTMLEmbedElementTable, 0 };

JSHTMLEmbedElement::JSHTMLEmbedElement(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<HTMLEmbedElement> impl)
    : JSHTMLElement(structure, globalObject, impl)
{
}

JSObject* JSHTMLEmbedElement::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSHTMLEmbedElementPrototype(JSHTMLEmbedElementPrototype::createStructure(JSHTMLElementPrototype::self(exec, globalObject)));
}

bool JSHTMLEmbedElement::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    if (canGetItemsForName(exec, static_cast<HTMLEmbedElement*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    if (getOwnPropertySlotDelegate(exec, propertyName, slot))
        return true;
    return getStaticValueSlot<JSHTMLEmbedElement, Base>(exec, &JSHTMLEmbedElementTable, this, propertyName, slot);
}

bool JSHTMLEmbedElement::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    if (canGetItemsForName(exec, static_cast<HTMLEmbedElement*>(impl()), propertyName)) {
        PropertySlot slot;
        slot.setCustom(this, nameGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), ReadOnly | DontDelete | DontEnum);
        return true;
    }
    if (getOwnPropertyDescriptorDelegate(exec, propertyName, descriptor))
        return true;
    return getStaticValueDescriptor<JSHTMLEmbedElement, Base>(exec, &JSHTMLEmbedElementTable, this, propertyName, descriptor);
}

JSValue jsHTMLEmbedElementAlign(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::alignAttr));
}

JSValue jsHTMLEmbedElementHeight(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::heightAttr));
}

JSValue jsHTMLEmbedElementName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::nameAttr));
}

JSValue jsHTMLEmbedElementSrc(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::srcAttr));
}

JSValue jsHTMLEmbedElementType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::typeAttr));
}

JSValue jsHTMLEmbedElementWidth(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* castedThis = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThis->impl());
    return jsString(exec, imp->getAttribute(HTMLNames::widthAttr));
}

JSValue jsHTMLEmbedElementConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSHTMLEmbedElement* domObject = static_cast<JSHTMLEmbedElement*>(asObject(slot.slotBase()));
    return JSHTMLEmbedElement::getConstructor(exec, domObject->globalObject());
}
void JSHTMLEmbedElement::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    if (putDelegate(exec, propertyName, value, slot))
        return;
    lookupPut<JSHTMLEmbedElement, Base>(exec, propertyName, value, &JSHTMLEmbedElementTable, this, slot);
}

void setJSHTMLEmbedElementAlign(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::alignAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLEmbedElementHeight(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::heightAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLEmbedElementName(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::nameAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLEmbedElementSrc(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::srcAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLEmbedElementType(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::typeAttr, valueToStringWithNullCheck(exec, value));
}

void setJSHTMLEmbedElementWidth(ExecState* exec, JSObject* thisObject, JSValue value)
{
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(static_cast<JSHTMLEmbedElement*>(thisObject)->impl());
    imp->setAttribute(HTMLNames::widthAttr, valueToStringWithNullCheck(exec, value));
}

JSValue JSHTMLEmbedElement::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSHTMLEmbedElementConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsHTMLEmbedElementPrototypeFunctionGetSVGDocument(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSHTMLEmbedElement::s_info))
        return throwError(exec, TypeError);
    JSHTMLEmbedElement* castedThisObj = static_cast<JSHTMLEmbedElement*>(asObject(thisValue));
    HTMLEmbedElement* imp = static_cast<HTMLEmbedElement*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    if (!checkNodeSecurity(exec, imp->getSVGDocument(ec)))
        return jsUndefined();


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->getSVGDocument(ec)));
    setDOMException(exec, ec);
    return result;
}


}
