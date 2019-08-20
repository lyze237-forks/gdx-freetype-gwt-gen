#include <stdint.h>

#include <emscripten.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H

#define jint int32_t

static jint lastError = 0;

jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_FreeType_getLastErrorCode() {
    return lastError;
}

void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_doneFreeType(jint library) {
    FT_Done_FreeType((FT_Library)library);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_newMemoryFace(jint library, jint data, jint dataSize, jint faceIndex) {
    FT_Face face = 0;
    FT_Error error = FT_New_Memory_Face((FT_Library)library, (FT_Byte*)data, dataSize, faceIndex, &face);
    if(error) {
        lastError = error;
        return 0;
    }
    else return (jint)face;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_strokerNew(jint library) {
    FT_Stroker stroker;
    FT_Error error = FT_Stroker_New((FT_Library)library, &stroker);
    if(error) {
        lastError = error;
        return 0;
    }
    else return (jint)stroker;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_doneFace(jint face) {
    FT_Done_Face((FT_Face)face);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getFaceFlags(jint face) {
    return ((FT_Face)face)->face_flags;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getStyleFlags(jint face) {
    return ((FT_Face)face)->style_flags;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getNumGlyphs(jint face) {
    return ((FT_Face)face)->num_glyphs;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getAscender(jint face) {
    return ((FT_Face)face)->ascender;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getDescender(jint face) {
    return ((FT_Face)face)->descender;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getHeight(jint face) {
    return ((FT_Face)face)->height;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getMaxAdvanceWidth(jint face) {
    return ((FT_Face)face)->max_advance_width;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getMaxAdvanceHeight(jint face) {
    return ((FT_Face)face)->max_advance_height;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getUnderlinePosition(jint face) {
    return ((FT_Face)face)->underline_position;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getUnderlineThickness(jint face) {
    return ((FT_Face)face)->underline_thickness;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_selectSize(jint face, jint strike_index) {
    return !FT_Select_Size((FT_Face)face, strike_index);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_setCharSize(jint face, jint charWidth, jint charHeight, jint horzResolution, jint vertResolution) {
    return !FT_Set_Char_Size((FT_Face)face, charWidth, charHeight, horzResolution, vertResolution);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_setPixelSizes(jint face, jint pixelWidth, jint pixelHeight) {
    return !FT_Set_Pixel_Sizes((FT_Face)face, pixelWidth, pixelHeight);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_loadGlyph(jint face, jint glyphIndex, jint loadFlags) {
    return !FT_Load_Glyph((FT_Face)face, glyphIndex, loadFlags);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_loadChar(jint face, jint charCode, jint loadFlags) {
    return !FT_Load_Char((FT_Face)face, charCode, loadFlags);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getGlyph(jint face) {
    return (jint)((FT_Face)face)->glyph;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getSize(jint face) {
    return (jint)((FT_Face)face)->size;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_hasKerning(jint face) {
    return FT_HAS_KERNING(((FT_Face)face));
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getKerning(jint face, jint leftGlyph, jint rightGlyph, jint kernMode) {
    FT_Vector kerning;
    FT_Error error = FT_Get_Kerning((FT_Face)face, leftGlyph, rightGlyph, kernMode, &kerning);
    if(error) {
        lastError = error;
        return 0;
    }
    return kerning.x;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getCharIndex(jint face, jint charCode) {
    return FT_Get_Char_Index((FT_Face)face, charCode);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Size_getMetrics(jint address) {
    return (jint)&((FT_Size)address)->metrics;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getXppem(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->x_ppem;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getYppem(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->y_ppem;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getXscale(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->x_scale;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getYscale(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->x_scale;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getAscender(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->ascender;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getDescender(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->descender;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getHeight(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->height;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getMaxAdvance(jint metrics) {
    return ((FT_Size_Metrics*)metrics)->max_advance;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getMetrics(jint slot) {
    return (jint)&((FT_GlyphSlot)slot)->metrics;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getLinearHoriAdvance(jint slot) {
    return ((FT_GlyphSlot)slot)->linearHoriAdvance;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getLinearVertAdvance(jint slot) {
    return ((FT_GlyphSlot)slot)->linearVertAdvance;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getAdvanceX(jint slot) {
    return ((FT_GlyphSlot)slot)->advance.x;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getAdvanceY(jint slot) {
    return ((FT_GlyphSlot)slot)->advance.y;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getFormat(jint slot) {
    return ((FT_GlyphSlot)slot)->format;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmap(jint slot) {
    FT_GlyphSlot glyph = ((FT_GlyphSlot)slot);
    return (jint)&(glyph->bitmap);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmapLeft(jint slot) {
    return ((FT_GlyphSlot)slot)->bitmap_left;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmapTop(jint slot) {
    return ((FT_GlyphSlot)slot)->bitmap_top;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_renderGlyph(jint slot, jint renderMode) {
    return !FT_Render_Glyph((FT_GlyphSlot)slot, (FT_Render_Mode)renderMode);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getGlyph(jint glyphSlot) {
    FT_Glyph glyph;
    FT_Error error = FT_Get_Glyph((FT_GlyphSlot)glyphSlot, &glyph);
    if(error) {
        lastError = error;
        return 0;
    }
    else return (jint)glyph;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_done(jint glyph) {
    FT_Done_Glyph((FT_Glyph)glyph);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_strokeBorder(jint glyph, jint stroker, jint inside) {
    FT_Glyph border_glyph = (FT_Glyph)glyph;
    FT_Glyph_StrokeBorder(&border_glyph, (FT_Stroker)stroker, inside, 1);
    return (jint)border_glyph;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_toBitmap(jint glyph, jint renderMode) {
    FT_Glyph bitmap = (FT_Glyph)glyph;
    FT_Error error = FT_Glyph_To_Bitmap(&bitmap, (FT_Render_Mode)renderMode, NULL, 1);
    if(error) {
        lastError = error;
        return 0;
    }
    return (jint)bitmap;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getBitmap(jint glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return (jint)&(glyph_bitmap->bitmap);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getLeft(jint glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return glyph_bitmap->left;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getTop(jint glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return glyph_bitmap->top;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getRows(jint bitmap) {
    return ((FT_Bitmap*)bitmap)->rows;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getWidth(jint bitmap) {
    return ((FT_Bitmap*)bitmap)->width;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getPitch(jint bitmap) {
    return ((FT_Bitmap*)bitmap)->pitch;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getBufferAddress(jint bitmap) {
    FT_Bitmap* bmp = (FT_Bitmap*)bitmap;
	return (jint)bmp->buffer;
    //return env->NewDirectByteBuffer((void*)bmp->buffer, bmp->rows * abs(bmp->pitch));
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getBufferSize(jint bitmap) {
    FT_Bitmap* bmp = (FT_Bitmap*)bitmap;
	return (jint)bmp->rows * abs(bmp->pitch) * bmp->width;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getNumGray(jint bitmap) {
    return ((FT_Bitmap*)bitmap)->num_grays;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getPixelMode(jint bitmap) {
    return ((FT_Bitmap*)bitmap)->pixel_mode;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getWidth(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->width;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHeight(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->height;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriBearingX(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiBearingX;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriBearingY(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiBearingY;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriAdvance(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiAdvance;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertBearingX(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertBearingX;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertBearingY(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertBearingY;
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertAdvance(jint metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertAdvance;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Stroker_set(jint stroker, jint radius, jint lineCap, jint lineJoin, jint miterLimit) {
    FT_Stroker_Set((FT_Stroker)stroker, radius, (FT_Stroker_LineCap)lineCap, (FT_Stroker_LineJoin)lineJoin, miterLimit);
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Stroker_done(jint stroker) {
    FT_Stroker_Done((FT_Stroker)stroker);
}
jint __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_FreeType_initFreeTypeJni() {
    FT_Library library = 0;
    FT_Error error = FT_Init_FreeType(&library);
    if(error) {
        lastError = error;
        return 0;
    }
    else return (jint)library;
}
