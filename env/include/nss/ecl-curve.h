/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "ecl-exp.h"
#include "eclt.h"
#include <stdlib.h>

#ifndef __ecl_curve_h_
#define __ecl_curve_h_

/* copied from certt.h */
#define KU_DIGITAL_SIGNATURE (0x80) /* bit 0 */
#define KU_KEY_AGREEMENT (0x08)     /* bit 4 */

static const PRUint8 irr256[32] = { 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
static const PRUint8 a256[32] = { 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC };
static const PRUint8 b256[32] = { 0x5A, 0xC6, 0x35, 0xD8, 0xAA, 0x3A, 0x93, 0xE7, 0xB3, 0xEB, 0xBD, 0x55,
                                  0x76, 0x98, 0x86, 0xBC, 0x65, 0x1D, 0x06, 0xB0, 0xCC, 0x53, 0xB0, 0xF6,
                                  0x3B, 0xCE, 0x3C, 0x3E, 0x27, 0xD2, 0x60, 0x4B };
static const PRUint8 x256[32] = { 0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, 0xF8, 0xBC, 0xE6, 0xE5,
                                  0x63, 0xA4, 0x40, 0xF2, 0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB, 0x33, 0xA0,
                                  0xF4, 0xA1, 0x39, 0x45, 0xD8, 0x98, 0xC2, 0x96 };
static const PRUint8 y256[32] = { 0x4F, 0xE3, 0x42, 0xE2, 0xFE, 0x1A, 0x7F, 0x9B, 0x8E, 0xE7, 0xEB, 0x4A,
                                  0x7C, 0x0F, 0x9E, 0x16, 0x2B, 0xCE, 0x33, 0x57, 0x6B, 0x31, 0x5E, 0xCE,
                                  0xCB, 0xB6, 0x40, 0x68, 0x37, 0xBF, 0x51, 0xF5 };
static const PRUint8 order256[32] = { 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
                                      0xFF, 0xFF, 0xFF, 0xFF, 0xBC, 0xE6, 0xFA, 0xAD, 0xA7, 0x17, 0x9E, 0x84,
                                      0xF3, 0xB9, 0xCA, 0xC2, 0xFC, 0x63, 0x25, 0x51 };
static const PRUint8 base256[66] = { 0x04, 0x00,
                                     0x6B, 0x17, 0xD1, 0xF2, 0xE1, 0x2C, 0x42, 0x47, 0xF8, 0xBC, 0xE6, 0xE5,
                                     0x63, 0xA4, 0x40, 0xF2, 0x77, 0x03, 0x7D, 0x81, 0x2D, 0xEB, 0x33, 0xA0,
                                     0xF4, 0xA1, 0x39, 0x45, 0xD8, 0x98, 0xC2, 0x96,
                                     0x4F, 0xE3, 0x42, 0xE2, 0xFE, 0x1A, 0x7F, 0x9B, 0x8E, 0xE7, 0xEB, 0x4A,
                                     0x7C, 0x0F, 0x9E, 0x16, 0x2B, 0xCE, 0x33, 0x57, 0x6B, 0x31, 0x5E, 0xCE,
                                     0xCB, 0xB6, 0x40, 0x68, 0x37, 0xBF, 0x51, 0xF5 };

static const ECCurveBytes ecCurve_NIST_P256 = {
    "NIST-P256", ECField_GFp, 256,
    irr256, a256, b256, x256, y256, order256, base256,
    1, 128, 66, 32,
    KU_DIGITAL_SIGNATURE | KU_KEY_AGREEMENT
};

static const PRUint8 irr384[48] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF };
static const PRUint8 a384[48] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFC };
static const PRUint8 b384[48] = { 0xB3, 0x31, 0x2F, 0xA7, 0xE2, 0x3E, 0xE7, 0xE4, 0x98, 0x8E, 0x05, 0x6B,
                                  0xE3, 0xF8, 0x2D, 0x19, 0x18, 0x1D, 0x9C, 0x6E, 0xFE, 0x81, 0x41, 0x12,
                                  0x03, 0x14, 0x08, 0x8F, 0x50, 0x13, 0x87, 0x5A, 0xC6, 0x56, 0x39, 0x8D,
                                  0x8A, 0x2E, 0xD1, 0x9D, 0x2A, 0x85, 0xC8, 0xED, 0xD3, 0xEC, 0x2A, 0xEF };
static const PRUint8 x384[48] = { 0xAA, 0x87, 0xCA, 0x22, 0xBE, 0x8B, 0x05, 0x37, 0x8E, 0xB1, 0xC7, 0x1E,
                                  0xF3, 0x20, 0xAD, 0x74, 0x6E, 0x1D, 0x3B, 0x62, 0x8B, 0xA7, 0x9B, 0x98,
                                  0x59, 0xF7, 0x41, 0xE0, 0x82, 0x54, 0x2A, 0x38, 0x55, 0x02, 0xF2, 0x5D,
                                  0xBF, 0x55, 0x29, 0x6C, 0x3A, 0x54, 0x5E, 0x38, 0x72, 0x76, 0x0A, 0xB7 };
static const PRUint8 y384[48] = { 0x36, 0x17, 0xDE, 0x4A, 0x96, 0x26, 0x2C, 0x6F, 0x5D, 0x9E, 0x98, 0xBF,
                                  0x92, 0x92, 0xDC, 0x29, 0xF8, 0xF4, 0x1D, 0xBD, 0x28, 0x9A, 0x14, 0x7C,
                                  0xE9, 0xDA, 0x31, 0x13, 0xB5, 0xF0, 0xB8, 0xC0, 0x0A, 0x60, 0xB1, 0xCE,
                                  0x1D, 0x7E, 0x81, 0x9D, 0x7A, 0x43, 0x1D, 0x7C, 0x90, 0xEA, 0x0E, 0x5F };
static const PRUint8 order384[48] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                      0xC7, 0x63, 0x4D, 0x81, 0xF4, 0x37, 0x2D, 0xDF, 0x58, 0x1A, 0x0D, 0xB2,
                                      0x48, 0xB0, 0xA7, 0x7A, 0xEC, 0xEC, 0x19, 0x6A, 0xCC, 0xC5, 0x29, 0x73 };
static const PRUint8 base384[98] = { 0x04, 0x00,
                                     0xAA, 0x87, 0xCA, 0x22, 0xBE, 0x8B, 0x05, 0x37, 0x8E, 0xB1, 0xC7, 0x1E,
                                     0xF3, 0x20, 0xAD, 0x74, 0x6E, 0x1D, 0x3B, 0x62, 0x8B, 0xA7, 0x9B, 0x98,
                                     0x59, 0xF7, 0x41, 0xE0, 0x82, 0x54, 0x2A, 0x38, 0x55, 0x02, 0xF2, 0x5D,
                                     0xBF, 0x55, 0x29, 0x6C, 0x3A, 0x54, 0x5E, 0x38, 0x72, 0x76, 0x0A, 0xB7,
                                     0x36, 0x17, 0xDE, 0x4A, 0x96, 0x26, 0x2C, 0x6F, 0x5D, 0x9E, 0x98, 0xBF,
                                     0x92, 0x92, 0xDC, 0x29, 0xF8, 0xF4, 0x1D, 0xBD, 0x28, 0x9A, 0x14, 0x7C,
                                     0xE9, 0xDA, 0x31, 0x13, 0xB5, 0xF0, 0xB8, 0xC0, 0x0A, 0x60, 0xB1, 0xCE,
                                     0x1D, 0x7E, 0x81, 0x9D, 0x7A, 0x43, 0x1D, 0x7C, 0x90, 0xEA, 0x0E, 0x5F };

static const ECCurveBytes ecCurve_NIST_P384 = {
    "NIST-P384", ECField_GFp, 384,
    irr384, a384, b384, x384, y384, order384, base384,
    1, 192, 98, 48,
    KU_DIGITAL_SIGNATURE | KU_KEY_AGREEMENT
};

static const PRUint8 irr521[66] = { 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
static const PRUint8 a521[66] = { 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC };
static const PRUint8 b521[66] = { 0x00, 0x51, 0x95, 0x3E, 0xB9, 0x61, 0x8E, 0x1C, 0x9A, 0x1F, 0x92, 0x9A,
                                  0x21, 0xA0, 0xB6, 0x85, 0x40, 0xEE, 0xA2, 0xDA, 0x72, 0x5B, 0x99, 0xB3,
                                  0x15, 0xF3, 0xB8, 0xB4, 0x89, 0x91, 0x8E, 0xF1, 0x09, 0xE1, 0x56, 0x19,
                                  0x39, 0x51, 0xEC, 0x7E, 0x93, 0x7B, 0x16, 0x52, 0xC0, 0xBD, 0x3B, 0xB1,
                                  0xBF, 0x07, 0x35, 0x73, 0xDF, 0x88, 0x3D, 0x2C, 0x34, 0xF1, 0xEF, 0x45,
                                  0x1F, 0xD4, 0x6B, 0x50, 0x3F, 0x00 };
static const PRUint8 x521[66] = { 0x00, 0xC6, 0x85, 0x8E, 0x06, 0xB7, 0x04, 0x04, 0xE9, 0xCD, 0x9E, 0x3E,
                                  0xCB, 0x66, 0x23, 0x95, 0xB4, 0x42, 0x9C, 0x64, 0x81, 0x39, 0x05, 0x3F,
                                  0xB5, 0x21, 0xF8, 0x28, 0xAF, 0x60, 0x6B, 0x4D, 0x3D, 0xBA, 0xA1, 0x4B,
                                  0x5E, 0x77, 0xEF, 0xE7, 0x59, 0x28, 0xFE, 0x1D, 0xC1, 0x27, 0xA2, 0xFF,
                                  0xA8, 0xDE, 0x33, 0x48, 0xB3, 0xC1, 0x85, 0x6A, 0x42, 0x9B, 0xF9, 0x7E,
                                  0x7E, 0x31, 0xC2, 0xE5, 0xBD, 0x66 };
static const PRUint8 y521[66] = { 0x01, 0x18, 0x39, 0x29, 0x6A, 0x78, 0x9A, 0x3B, 0xC0, 0x04, 0x5C, 0x8A,
                                  0x5F, 0xB4, 0x2C, 0x7D, 0x1B, 0xD9, 0x98, 0xF5, 0x44, 0x49, 0x57, 0x9B,
                                  0x44, 0x68, 0x17, 0xAF, 0xBD, 0x17, 0x27, 0x3E, 0x66, 0x2C, 0x97, 0xEE,
                                  0x72, 0x99, 0x5E, 0xF4, 0x26, 0x40, 0xC5, 0x50, 0xB9, 0x01, 0x3F, 0xAD,
                                  0x07, 0x61, 0x35, 0x3C, 0x70, 0x86, 0xA2, 0x72, 0xC2, 0x40, 0x88, 0xBE,
                                  0x94, 0x76, 0x9F, 0xD1, 0x66, 0x50 };
static const PRUint8 order521[66] = { 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                      0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFA, 0x51, 0x86,
                                      0x87, 0x83, 0xBF, 0x2F, 0x96, 0x6B, 0x7F, 0xCC, 0x01, 0x48, 0xF7, 0x09,
                                      0xA5, 0xD0, 0x3B, 0xB5, 0xC9, 0xB8, 0x89, 0x9C, 0x47, 0xAE, 0xBB, 0x6F,
                                      0xB7, 0x1E, 0x91, 0x38, 0x64, 0x09 };
static const PRUint8 base521[134] = {
    0x04, 0x00,
    0x00, 0xC6, 0x85, 0x8E, 0x06, 0xB7, 0x04, 0x04, 0xE9, 0xCD, 0x9E, 0x3E,
    0xCB, 0x66, 0x23, 0x95, 0xB4, 0x42, 0x9C, 0x64, 0x81, 0x39, 0x05, 0x3F,
    0xB5, 0x21, 0xF8, 0x28, 0xAF, 0x60, 0x6B, 0x4D, 0x3D, 0xBA, 0xA1, 0x4B,
    0x5E, 0x77, 0xEF, 0xE7, 0x59, 0x28, 0xFE, 0x1D, 0xC1, 0x27, 0xA2, 0xFF,
    0xA8, 0xDE, 0x33, 0x48, 0xB3, 0xC1, 0x85, 0x6A, 0x42, 0x9B, 0xF9, 0x7E,
    0x7E, 0x31, 0xC2, 0xE5, 0xBD, 0x66,
    0x01, 0x18, 0x39, 0x29, 0x6A, 0x78, 0x9A, 0x3B, 0xC0, 0x04, 0x5C, 0x8A,
    0x5F, 0xB4, 0x2C, 0x7D, 0x1B, 0xD9, 0x98, 0xF5, 0x44, 0x49, 0x57, 0x9B,
    0x44, 0x68, 0x17, 0xAF, 0xBD, 0x17, 0x27, 0x3E, 0x66, 0x2C, 0x97, 0xEE,
    0x72, 0x99, 0x5E, 0xF4, 0x26, 0x40, 0xC5, 0x50, 0xB9, 0x01, 0x3F, 0xAD,
    0x07, 0x61, 0x35, 0x3C, 0x70, 0x86, 0xA2, 0x72, 0xC2, 0x40, 0x88, 0xBE,
    0x94, 0x76, 0x9F, 0xD1, 0x66, 0x50
};

static const ECCurveBytes ecCurve_NIST_P521 = {
    "NIST-P521", ECField_GFp, 521,
    irr521, a521, b521, x521, y521, order521, base521,
    1, 256, 134, 66,
    KU_DIGITAL_SIGNATURE | KU_KEY_AGREEMENT
};

static const PRUint8 irr25519[32] = { 0xed, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f };
static const PRUint8 a25519[32] = { 0x06, 0x6d, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static const PRUint8 b25519[32] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
static const PRUint8 x25519[32] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09 };
static const PRUint8 y25519[32] = { 0xd9, 0xd3, 0xce, 0x7e, 0xa2, 0xc5, 0xe9, 0x29, 0xb2, 0x61, 0x7c, 0x6d,
                                    0x7e, 0x4d, 0x3d, 0x92, 0x4c, 0xd1, 0x48, 0x77, 0x2c, 0xdd, 0x1e, 0xe0,
                                    0xb4, 0x86, 0xa0, 0xb8, 0xa1, 0x19, 0xae, 0x20 };
static const PRUint8 order25519[32] = { 0xed, 0xd3, 0xf5, 0x5c, 0x1a, 0x63, 0x12, 0x58, 0xd6, 0x9c, 0xf7, 0xa2,
                                        0xde, 0xf9, 0xde, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10 };
static const PRUint8 base25519[66] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
                                       0xd9, 0xd3, 0xce, 0x7e, 0xa2, 0xc5, 0xe9, 0x29, 0xb2, 0x61, 0x7c, 0x6d,
                                       0x7e, 0x4d, 0x3d, 0x92, 0x4c, 0xd1, 0x48, 0x77, 0x2c, 0xdd, 0x1e, 0xe0,
                                       0xb4, 0x86, 0xa0, 0xb8, 0xa1, 0x19, 0xae, 0x20, 0x00, 0x04 };

static const ECCurveBytes ecCurve_25519 = {
    "Curve25519", ECField_GFp, 255,
    irr25519, a25519, b25519, x25519, y25519, order25519, base25519,
    8, 128, 66, 32,
    KU_KEY_AGREEMENT
};

/* mapping between ECCurveName enum and pointers to ECCurveParams */
static const ECCurveBytes *ecCurve_map[] = {
    NULL,               /* ECCurve_noName */
    NULL,               /* ECCurve_NIST_P192 */
    NULL,               /* ECCurve_NIST_P224 */
    &ecCurve_NIST_P256, /* ECCurve_NIST_P256 */
    &ecCurve_NIST_P384, /* ECCurve_NIST_P384 */
    &ecCurve_NIST_P521, /* ECCurve_NIST_P521 */
    NULL,               /* ECCurve_NIST_K163 */
    NULL,               /* ECCurve_NIST_B163 */
    NULL,               /* ECCurve_NIST_K233 */
    NULL,               /* ECCurve_NIST_B233 */
    NULL,               /* ECCurve_NIST_K283 */
    NULL,               /* ECCurve_NIST_B283 */
    NULL,               /* ECCurve_NIST_K409 */
    NULL,               /* ECCurve_NIST_B409 */
    NULL,               /* ECCurve_NIST_K571 */
    NULL,               /* ECCurve_NIST_B571 */
    NULL,               /* ECCurve_X9_62_PRIME_192V2 */
    NULL,               /* ECCurve_X9_62_PRIME_192V3 */
    NULL,               /* ECCurve_X9_62_PRIME_239V1 */
    NULL,               /* ECCurve_X9_62_PRIME_239V2 */
    NULL,               /* ECCurve_X9_62_PRIME_239V3 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB163V1 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB163V2 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB163V3 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB176V1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB191V1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB191V2 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB191V3 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB208W1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB239V1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB239V2 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB239V3 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB272W1 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB304W1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB359V1 */
    NULL,               /* ECCurve_X9_62_CHAR2_PNB368W1 */
    NULL,               /* ECCurve_X9_62_CHAR2_TNB431R1 */
    NULL,               /* ECCurve_SECG_PRIME_112R1 */
    NULL,               /* ECCurve_SECG_PRIME_112R2 */
    NULL,               /* ECCurve_SECG_PRIME_128R1 */
    NULL,               /* ECCurve_SECG_PRIME_128R2 */
    NULL,               /* ECCurve_SECG_PRIME_160K1 */
    NULL,               /* ECCurve_SECG_PRIME_160R1 */
    NULL,               /* ECCurve_SECG_PRIME_160R2 */
    NULL,               /* ECCurve_SECG_PRIME_192K1 */
    NULL,               /* ECCurve_SECG_PRIME_224K1 */
    NULL,               /* ECCurve_SECG_PRIME_256K1 */
    NULL,               /* ECCurve_SECG_CHAR2_113R1 */
    NULL,               /* ECCurve_SECG_CHAR2_113R2 */
    NULL,               /* ECCurve_SECG_CHAR2_131R1 */
    NULL,               /* ECCurve_SECG_CHAR2_131R2 */
    NULL,               /* ECCurve_SECG_CHAR2_163R1 */
    NULL,               /* ECCurve_SECG_CHAR2_193R1 */
    NULL,               /* ECCurve_SECG_CHAR2_193R2 */
    NULL,               /* ECCurve_SECG_CHAR2_239K1 */
    NULL,               /* ECCurve_WTLS_1 */
    NULL,               /* ECCurve_WTLS_8 */
    NULL,               /* ECCurve_WTLS_9 */
    &ecCurve_25519,     /* ECCurve25519 */
    NULL                /* ECCurve_pastLastCurve */
};

#endif
