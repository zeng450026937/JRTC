cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME "Boost")

project(${PROJECT_NAME})

message(STATUS "Configuring ${PROJECT_NAME}")

add_definitions(
	-DBOOST_ALL_NO_LIB
	-DBOOST_SYSTEM_NO_DEPRECATED
)

include_directories(
	src
)

if(WIN32)
	add_definitions(-D_WIN32_WINNT=0x0600)
endif()

set(SRC
	"src/libs/atomic/src/lockpool.cpp"
	"src/libs/date_time/src/gregorian/date_generators.cpp"
	"src/libs/date_time/src/gregorian/greg_month.cpp"
	"src/libs/date_time/src/gregorian/greg_weekday.cpp"
	"src/libs/date_time/src/gregorian/gregorian_types.cpp"
	"src/libs/date_time/src/posix_time/posix_time_types.cpp"
	"src/libs/system/src/error_code.cpp"
	"src/libs/filesystem/src/codecvt_error_category.cpp"
	"src/libs/filesystem/src/operations.cpp"
	"src/libs/filesystem/src/path.cpp"
	"src/libs/filesystem/src/path_traits.cpp"
	"src/libs/filesystem/src/portability.cpp"
	"src/libs/filesystem/src/unique_path.cpp"
	"src/libs/filesystem/src/windows_file_codecvt.cpp"
	"src/libs/filesystem/src/filesystem_utf8_codecvt_facet.cpp"
	"src/libs/regex/src/c_regex_traits.cpp"
	"src/libs/regex/src/cpp_regex_traits.cpp"
	"src/libs/regex/src/cregex.cpp"
	"src/libs/regex/src/fileiter.cpp"
	"src/libs/regex/src/icu.cpp"
	"src/libs/regex/src/instances.cpp"
	"src/libs/regex/src/posix_api.cpp"
	"src/libs/regex/src/regex.cpp"
	"src/libs/regex/src/regex_debug.cpp"
	"src/libs/regex/src/regex_raw_buffer.cpp"
	"src/libs/regex/src/regex_traits_defaults.cpp"
	"src/libs/regex/src/static_mutex.cpp"
	"src/libs/regex/src/w32_regex_traits.cpp"
	"src/libs/regex/src/wc_regex_traits.cpp"
	"src/libs/regex/src/wide_posix_api.cpp"
	"src/libs/regex/src/winstances.cpp"
	"src/libs/regex/src/usinstances.cpp"
	"src/libs/program_options/src/cmdline.cpp"
	"src/libs/program_options/src/config_file.cpp"
	"src/libs/program_options/src/convert.cpp"
	"src/libs/program_options/src/options_description.cpp"
	"src/libs/program_options/src/positional_options.cpp"
	"src/libs/program_options/src/split.cpp"
	"src/libs/program_options/src/program_options_utf8_codecvt_facet.cpp"
	"src/libs/program_options/src/value_semantic.cpp"
	"src/libs/program_options/src/variables_map.cpp"
	"src/libs/program_options/src/winmain.cpp"
	"src/libs/serialization/src/archive_exception.cpp"
	"src/libs/serialization/src/basic_archive.cpp"
	"src/libs/serialization/src/basic_iarchive.cpp"
	"src/libs/serialization/src/basic_iserializer.cpp"
	"src/libs/serialization/src/basic_oarchive.cpp"
	"src/libs/serialization/src/basic_oserializer.cpp"
	"src/libs/serialization/src/basic_pointer_iserializer.cpp"
	"src/libs/serialization/src/basic_pointer_oserializer.cpp"
	"src/libs/serialization/src/basic_serializer_map.cpp"
	"src/libs/serialization/src/basic_text_iprimitive.cpp"
	"src/libs/serialization/src/basic_text_oprimitive.cpp"
	"src/libs/serialization/src/basic_text_wiprimitive.cpp"
	"src/libs/serialization/src/basic_text_woprimitive.cpp"
	"src/libs/serialization/src/basic_xml_archive.cpp"
	"src/libs/serialization/src/binary_iarchive.cpp"
	"src/libs/serialization/src/binary_oarchive.cpp"
	"src/libs/serialization/src/binary_wiarchive.cpp"
	"src/libs/serialization/src/binary_woarchive.cpp"
	"src/libs/serialization/src/codecvt_null.cpp"
	"src/libs/serialization/src/extended_type_info.cpp"
	"src/libs/serialization/src/extended_type_info_no_rtti.cpp"
	"src/libs/serialization/src/extended_type_info_typeid.cpp"
	"src/libs/serialization/src/polymorphic_iarchive.cpp"
	"src/libs/serialization/src/polymorphic_oarchive.cpp"
	"src/libs/serialization/src/stl_port.cpp"
	"src/libs/serialization/src/text_iarchive.cpp"
	"src/libs/serialization/src/text_oarchive.cpp"
	"src/libs/serialization/src/text_wiarchive.cpp"
	"src/libs/serialization/src/text_woarchive.cpp"
	"src/libs/serialization/src/utf8_codecvt_facet.cpp"
	"src/libs/serialization/src/void_cast.cpp"
	"src/libs/serialization/src/xml_archive_exception.cpp"
	"src/libs/serialization/src/xml_grammar.cpp"
	"src/libs/serialization/src/xml_iarchive.cpp"
	"src/libs/serialization/src/xml_oarchive.cpp"
	"src/libs/serialization/src/xml_wgrammar.cpp"
	"src/libs/serialization/src/xml_wiarchive.cpp"
	"src/libs/serialization/src/xml_woarchive.cpp"
)

if(NOT APPLE)
	list(APPEND SRC
		"src/libs/program_options/src/parsers.cpp"
	)
endif()

add_library(${PROJECT_NAME} ${SRC})

	