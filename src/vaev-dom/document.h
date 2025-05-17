#pragma once

#include <karm-mime/url.h>

#include "node.h"

namespace Vaev::Style {

struct StyleSheetList;

} // namespace Vaev::Style

namespace Vaev::Dom {

enum struct QuirkMode {
    NO,
    LIMITED,
    YES
};

// https://dom.spec.whatwg.org/#interface-document
struct Document : Node {
    static constexpr auto TYPE = NodeType::DOCUMENT;

    Mime::Url _url;
    QuirkMode quirkMode{QuirkMode::NO};

    String xmlVersion;
    String xmlEncoding;
    String xmlStandalone = "no"s; // https://www.w3.org/TR/xml/#NT-SDDecl

    Gc::Ptr<Style::StyleSheetList> styleSheets;

    Document(Mime::Url url)
        : _url(url) {
    }

    NodeType nodeType() const override {
        return TYPE;
    }

    String title();

    Mime::Url const& url() const {
        return _url;
    }

    Gc::Ptr<Element> documentElement() const;
};

} // namespace Vaev::Dom
