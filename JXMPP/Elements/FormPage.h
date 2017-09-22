#ifndef JXMPP_FORMPAGE_H
#define JXMPP_FORMPAGE_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/FormField.h>
#include <JXMPP/Elements/FormReportedRef.h>
#include <JXMPP/Elements/FormSection.h>
#include <JXMPP/Elements/FormText.h>

namespace JXMPP {

    class JXMPP_API FormPage {
        public:
            typedef std::shared_ptr<FormPage> page;
            FormPage ();
            ~FormPage();
            void setLabel(const std::string& label);
            const std::string& getLabel() const;
            void addChildSection(std::shared_ptr<FormSection> section);
            const std::vector<std::shared_ptr<FormSection> >& getChildSections() const;
            void addTextElement(std::shared_ptr<FormText> textElement);
            const std::vector<std::shared_ptr<FormText> >& getTextElements() const;
            void addReportedRef(std::shared_ptr<FormReportedRef> reportedRef);
            const std::vector<std::shared_ptr<FormReportedRef> >& getReportedRefs() const;
            void addField(std::shared_ptr<FormField> field);
            const std::vector<std::shared_ptr<FormField> >& getFields() const;
            void addFieldRef(std::string ref);
            const std::vector<std::string> getFieldRefs() const;

        private:
            std::string label_;
            std::vector<std::shared_ptr<FormText> > textElements_;
            std::vector<std::shared_ptr<FormSection> > childSections_;
            std::vector<std::shared_ptr<FormReportedRef> > reportedRefs_;
            std::vector<std::shared_ptr<FormField> > fields_;
            std::vector<std::string> fieldRefs_;
    };
}

#endif // JXMPP_FORMPAGE_H
