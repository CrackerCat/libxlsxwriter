/*
 * Tests for the libxlsxwriter library.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 * Copyright 2014-2025, John McNamara, jmcnamara@cpan.org.
 *
 */

#include "../ctest.h"
#include "../helper.h"

#include "../../../include/xlsxwriter/drawing.h"

// Test _xml_declaration().
CTEST(drawing, xml_declaration) {

    char* got;
    char exp[] = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>\n";
    FILE* testfile = lxw_tmpfile(NULL);

    lxw_drawing *drawing = lxw_drawing_new();
    drawing->file = testfile;

    _drawing_xml_declaration(drawing);

    RUN_XLSX_STREQ(exp, got);

    lxw_drawing_free(drawing);
}
