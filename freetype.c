#include <emscripten.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_doneFreeType(long library) {
    FT_Done_FreeType((FT_Library)library);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_newMemoryFace(long library, long data, int dataSize, int faceIndex) {
    FT_Face face = 0;
    FT_Error error = FT_New_Memory_Face((FT_Library)library, (FT_Byte*)data, dataSize, faceIndex, &face);
    if(error) return 0;
    else return (long)face;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Library_strokerNew(long library) {
    FT_Stroker stroker;
    FT_Error error = FT_Stroker_New((FT_Library)library, &stroker);
    if(error) return 0;
    else return (long)stroker;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_doneFace(long face) {
    FT_Done_Face((FT_Face)face);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getFaceFlags(long face) {
    return ((FT_Face)face)->face_flags;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getStyleFlags(long face) {
    return ((FT_Face)face)->style_flags;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getNumGlyphs(long face) {
    return ((FT_Face)face)->num_glyphs;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getAscender(long face) {
    return ((FT_Face)face)->ascender;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getDescender(long face) {
    return ((FT_Face)face)->descender;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getHeight(long face) {
    return ((FT_Face)face)->height;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getMaxAdvanceWidth(long face) {
    return ((FT_Face)face)->max_advance_width;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getMaxAdvanceHeight(long face) {
    return ((FT_Face)face)->max_advance_height;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getUnderlinePosition(long face) {
    return ((FT_Face)face)->underline_position;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getUnderlineThickness(long face) {
    return ((FT_Face)face)->underline_thickness;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_selectSize(long face, int strike_index) {
    return !FT_Select_Size((FT_Face)face, strike_index);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_setCharSize(long face, int charWidth, int charHeight, int horzResolution, int vertResolution) {
    return !FT_Set_Char_Size((FT_Face)face, charWidth, charHeight, horzResolution, vertResolution);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_setPixelSizes(long face, int pixelWidth, int pixelHeight) {
    return !FT_Set_Pixel_Sizes((FT_Face)face, pixelWidth, pixelHeight);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_loadGlyph(long face, int glyphIndex, int loadFlags) {
    return !FT_Load_Glyph((FT_Face)face, glyphIndex, loadFlags);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_loadChar(long face, int charCode, int loadFlags) {
    return !FT_Load_Char((FT_Face)face, charCode, loadFlags);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getGlyph(long face) {
    return (long)((FT_Face)face)->glyph;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getSize(long face) {
    return (long)((FT_Face)face)->size;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_hasKerning(long face) {
    return FT_HAS_KERNING(((FT_Face)face));
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getKerning(long face, int leftGlyph, int rightGlyph, int kernMode) {
    FT_Vector kerning;
    FT_Error error = FT_Get_Kerning((FT_Face)face, leftGlyph, rightGlyph, kernMode, &kerning);
    if(error) return 0;
    return kerning.x;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Face_getCharIndex(long face, int charCode) {
    return FT_Get_Char_Index((FT_Face)face, charCode);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Size_getMetrics(long address) {
    return (long)&((FT_Size)address)->metrics;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getXppem(long metrics) {
    return ((FT_Size_Metrics*)metrics)->x_ppem;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getYppem(long metrics) {
    return ((FT_Size_Metrics*)metrics)->y_ppem;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getXscale(long metrics) {
    return ((FT_Size_Metrics*)metrics)->x_scale;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getYscale(long metrics) {
    return ((FT_Size_Metrics*)metrics)->x_scale;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getAscender(long metrics) {
    return ((FT_Size_Metrics*)metrics)->ascender;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getDescender(long metrics) {
    return ((FT_Size_Metrics*)metrics)->descender;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getHeight(long metrics) {
    return ((FT_Size_Metrics*)metrics)->height;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_SizeMetrics_getMaxAdvance(long metrics) {
    return ((FT_Size_Metrics*)metrics)->max_advance;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getMetrics(long slot) {
    return (long)&((FT_GlyphSlot)slot)->metrics;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getLinearHoriAdvance(long slot) {
    return ((FT_GlyphSlot)slot)->linearHoriAdvance;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getLinearVertAdvance(long slot) {
    return ((FT_GlyphSlot)slot)->linearVertAdvance;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getAdvanceX(long slot) {
    return ((FT_GlyphSlot)slot)->advance.x;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getAdvanceY(long slot) {
    return ((FT_GlyphSlot)slot)->advance.y;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getFormat(long slot) {
    return ((FT_GlyphSlot)slot)->format;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmap(long slot) {
    FT_GlyphSlot glyph = ((FT_GlyphSlot)slot);
    return (long)&(glyph->bitmap);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmapLeft(long slot) {
    return ((FT_GlyphSlot)slot)->bitmap_left;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getBitmapTop(long slot) {
    return ((FT_GlyphSlot)slot)->bitmap_top;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_renderGlyph(long slot, int renderMode) {
    return !FT_Render_Glyph((FT_GlyphSlot)slot, (FT_Render_Mode)renderMode);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphSlot_getGlyph(long glyphSlot) {
    FT_Glyph glyph;
    FT_Error error = FT_Get_Glyph((FT_GlyphSlot)glyphSlot, &glyph);
    if(error) return 0;
    else return (long)glyph;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_done(long glyph) {
    FT_Done_Glyph((FT_Glyph)glyph);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_strokeBorder(long glyph, long stroker, int inside) {
    FT_Glyph border_glyph = (FT_Glyph)glyph;
    FT_Glyph_StrokeBorder(&border_glyph, (FT_Stroker)stroker, inside, 1);
    return (long)border_glyph;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_toBitmap(long glyph, int renderMode) {
    FT_Glyph bitmap = (FT_Glyph)glyph;
    FT_Error error = FT_Glyph_To_Bitmap(&bitmap, (FT_Render_Mode)renderMode, NULL, 1);
    if(error) return 0;
    return (long)bitmap;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getBitmap(long glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return (long)&(glyph_bitmap->bitmap);
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getLeft(long glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return glyph_bitmap->left;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Glyph_getTop(long glyph) {
    FT_BitmapGlyph glyph_bitmap = ((FT_BitmapGlyph)glyph);
    return glyph_bitmap->top;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getRows(long bitmap) {
    return ((FT_Bitmap*)bitmap)->rows;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getWidth(long bitmap) {
    return ((FT_Bitmap*)bitmap)->width;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getPitch(long bitmap) {
    return ((FT_Bitmap*)bitmap)->pitch;
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getBufferAddress(long bitmap) {
    FT_Bitmap* bmp = (FT_Bitmap*)bitmap;
	return (long)bmp->buffer;
    //return env->NewDirectByteBuffer((void*)bmp->buffer, bmp->rows * abs(bmp->pitch));
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getBufferSize(long bitmap) {
    FT_Bitmap* bmp = (FT_Bitmap*)bitmap;
	return (long)bmp->rows * abs(bmp->pitch) * bmp->width;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getNumGray(long bitmap) {
    return ((FT_Bitmap*)bitmap)->num_grays;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Bitmap_getPixelMode(long bitmap) {
    return ((FT_Bitmap*)bitmap)->pixel_mode;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getWidth(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->width;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHeight(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->height;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriBearingX(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiBearingX;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriBearingY(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiBearingY;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getHoriAdvance(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->horiAdvance;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertBearingX(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertBearingX;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertBearingY(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertBearingY;
}
int __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_GlyphMetrics_getVertAdvance(long metrics) {
    return ((FT_Glyph_Metrics*)metrics)->vertAdvance;
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Stroker_set(long stroker, int radius, int lineCap, int lineJoin, int miterLimit) {
    FT_Stroker_Set((FT_Stroker)stroker, radius, (FT_Stroker_LineCap)lineCap, (FT_Stroker_LineJoin)lineJoin, miterLimit);
}
void __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_Stroker_done(long stroker) {
    FT_Stroker_Done((FT_Stroker)stroker);
}
long __attribute__((used)) EMSCRIPTEN_KEEPALIVE c_FreeType_initFreeTypeJni() {
    FT_Library library = 0;
    FT_Error error = FT_Init_FreeType(&library);
    if(error) return 0;
    else return (long)library;
}
