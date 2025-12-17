//===- AttrOrTypeCAPIGen.cpp - MLIR Attribute and Type CAPI generation ----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "mlir/TableGen/GenInfo.h"
#include "mlir/TableGen/Pass.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/FormatVariadic.h"
#include "llvm/TableGen/Error.h"
#include "llvm/TableGen/Record.h"

using namespace mlir;
using namespace mlir::tblgen;
using llvm::formatv;
using llvm::RecordKeeper;

static llvm::cl::OptionCategory
    passGenCat("Options for -gen-attr-or-type-capi-header and "
               "-gen-attr-or-type-capi-impl");

const char *const gettorDecl = R"(
MLIR_CAPI_EXPORTED MlirType mlir{0}TypeGet({1});

)";

const char *const gettorDefn = R"(
MLIR_CAPI_EXPORTED MlirType mlir{0}TypeGet({1})
{
  return wrap({0}Type::get({2}));
}

)";

static bool emitCAPIHeader(const RecordKeeper &records, raw_ostream &os) {}

static bool emitCAPIImpl(const RecordKeeper &records, raw_ostream &os) {}

static mlir::GenRegistration
    genCAPIHeader("gen-attr-or-type-capi-header",
                  "Generate Attribute or Type C API header", &emitCAPIHeader);

static mlir::GenRegistration
    genCAPIImpl("gen-attr-or-type-capi-impl",
                "Generate Attribute or Type C API implementation",
                &emitCAPIImpl);
