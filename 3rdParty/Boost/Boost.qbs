import qbs

Product {
    name: "Boost"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.defines: ["BOOST_ALL_NO_LIB", "BOOST_SYSTEM_NO_DEPRECATED"]
    cpp.includePaths: ["src"]

    Properties {
        // 0x0600 = _WIN32_WINNT_VISTA
        condition: qbs.targetOS.contains("windows")
        cpp.defines: outer.concat(["_WIN32_WINNT=0x0600"])
    }
    Properties {
        condition: qbs.targetOS.contains("cygwin")
        cpp.defines: outer.concat(["__USE_W32_SOCKETS"])
    }
    Properties {
        condition: qbs.targetOS.contains("posix")
        cpp.staticLibraries: outer.concat(["rt"])
    }

    Group {
        name: "source file"
        prefix: "src/libs/"
        files: ["atomic/src/lockpool.cpp", "date_time/src/gregorian/date_generators.cpp", "date_time/src/gregorian/greg_month.cpp", "date_time/src/gregorian/greg_weekday.cpp", "date_time/src/gregorian/gregorian_types.cpp", "date_time/src/posix_time/posix_time_types.cpp", "system/src/error_code.cpp", "filesystem/src/codecvt_error_category.cpp", "filesystem/src/operations.cpp", "filesystem/src/path.cpp", "filesystem/src/path_traits.cpp", "filesystem/src/portability.cpp", "filesystem/src/unique_path.cpp", "filesystem/src/windows_file_codecvt.cpp", "filesystem/src/filesystem_utf8_codecvt_facet.cpp", "regex/src/c_regex_traits.cpp", "regex/src/cpp_regex_traits.cpp", "regex/src/cregex.cpp", "regex/src/fileiter.cpp", "regex/src/icu.cpp", "regex/src/instances.cpp", "regex/src/posix_api.cpp", "regex/src/regex.cpp", "regex/src/regex_debug.cpp", "regex/src/regex_raw_buffer.cpp", "regex/src/regex_traits_defaults.cpp", "regex/src/static_mutex.cpp", "regex/src/w32_regex_traits.cpp", "regex/src/wc_regex_traits.cpp", "regex/src/wide_posix_api.cpp", "regex/src/winstances.cpp", "regex/src/usinstances.cpp", "program_options/src/cmdline.cpp", "program_options/src/config_file.cpp", "program_options/src/convert.cpp", "program_options/src/options_description.cpp", "program_options/src/positional_options.cpp", "program_options/src/split.cpp", "program_options/src/program_options_utf8_codecvt_facet.cpp", "program_options/src/value_semantic.cpp", "program_options/src/variables_map.cpp", "program_options/src/winmain.cpp", "serialization/src/archive_exception.cpp", "serialization/src/basic_archive.cpp", "serialization/src/basic_iarchive.cpp", "serialization/src/basic_iserializer.cpp", "serialization/src/basic_oarchive.cpp", "serialization/src/basic_oserializer.cpp", "serialization/src/basic_pointer_iserializer.cpp", "serialization/src/basic_pointer_oserializer.cpp", "serialization/src/basic_serializer_map.cpp", "serialization/src/basic_text_iprimitive.cpp", "serialization/src/basic_text_oprimitive.cpp", "serialization/src/basic_text_wiprimitive.cpp", "serialization/src/basic_text_woprimitive.cpp", "serialization/src/basic_xml_archive.cpp", "serialization/src/binary_iarchive.cpp", "serialization/src/binary_oarchive.cpp", "serialization/src/binary_wiarchive.cpp", "serialization/src/binary_woarchive.cpp", "serialization/src/codecvt_null.cpp", "serialization/src/extended_type_info.cpp", "serialization/src/extended_type_info_no_rtti.cpp", "serialization/src/extended_type_info_typeid.cpp", "serialization/src/polymorphic_iarchive.cpp", "serialization/src/polymorphic_oarchive.cpp", "serialization/src/stl_port.cpp", "serialization/src/text_iarchive.cpp", "serialization/src/text_oarchive.cpp", "serialization/src/text_wiarchive.cpp", "serialization/src/text_woarchive.cpp", "serialization/src/utf8_codecvt_facet.cpp", "serialization/src/void_cast.cpp", "serialization/src/xml_archive_exception.cpp", "serialization/src/xml_grammar.cpp", "serialization/src/xml_iarchive.cpp", "serialization/src/xml_oarchive.cpp", "serialization/src/xml_wgrammar.cpp", "serialization/src/xml_wiarchive.cpp", "serialization/src/xml_woarchive.cpp"]
    }

    Group {
        condition: !qbs.targetOS.contains("darwin")
        prefix: "src/libs/"
        files: ["program_options/src/parsers.cpp"]
    }

    Export {
        Depends { name: "cpp" }
        cpp.defines: ["HAVE_" + product.name.toUpperCase()]
        cpp.includePaths: product.cpp.includePaths
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
}
