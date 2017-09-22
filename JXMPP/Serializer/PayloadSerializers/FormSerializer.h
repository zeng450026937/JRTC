#ifndef JXMPP_FORMSERIALIZER_H
#define JXMPP_FORMSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/FormField.h>
#include <JXMPP/Elements/FormPage.h>
#include <JXMPP/Elements/FormSection.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API FormSerializer : public GenericPayloadSerializer<Form> {
        public:
            FormSerializer();
            virtual std::string serializePayload(std::shared_ptr<Form>)  const;

        private:
            std::shared_ptr<XMLElement> textToXML(std::shared_ptr<FormText> textElement) const;
            std::shared_ptr<XMLElement> fieldRefToXML(const std::string& ref) const;
            std::shared_ptr<XMLElement> reportedRefToXML(std::shared_ptr<FormReportedRef> reportedRef) const;
            std::shared_ptr<XMLElement> pageToXML(std::shared_ptr<FormPage> page) const;
            std::shared_ptr<XMLElement> sectionToXML(std::shared_ptr<FormSection> section) const;
            std::shared_ptr<XMLElement> fieldToXML(std::shared_ptr<FormField> field, bool withTypeAttribute) const;
            void multiLineify(const std::string& text, const std::string& elementName, std::shared_ptr<XMLElement> parent) const;
            mutable std::vector<std::shared_ptr<FormField> > fields_;
    };
}

#endif // JXMPP_FORMSERIALIZER_H
