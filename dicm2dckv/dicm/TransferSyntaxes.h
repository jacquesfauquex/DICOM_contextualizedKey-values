//
//  TransferSyntaxes.h
//  dicm2dckv
//
//  Created by jacquesfauquex on 2024-02-29.
//

#ifndef TransferSyntaxes_h
#define TransferSyntaxes_h

enum sopkeyenum{
PapyrusImplicitVRLittleEndian,
ImplicitVRLittleEndian,
ExplicitVRLittleEndian,
EncapsulatedUncompressedExplicitVRLittleEndian,
DeflatedExplicitVRLittleEndian,
ExplicitVRBigEndianRetired,
JPEGBaseline8Bit,
JPEGExtended12Bit,
JPEGExtended35Retired,
JPEGSpectralSelectionNonHierarchical68Retired,
JPEGSpectralSelectionNonHierarchical79Retired,
JPEGFullProgressionNonHierarchical1012Retired,
JPEGFullProgressionNonHierarchical1113Retired,
JPEGLossless,
JPEGLosslessNonHierarchical15Retired,
JPEGExtendedHierarchical1618Retired,
JPEGExtendedHierarchical1719Retired,
JPEGSpectralSelectionHierarchical2022Retired,
JPEGSpectralSelectionHierarchical2123Retired,
JPEGFullProgressionHierarchical2426Retired,
JPEGFullProgressionHierarchical2527Retired,
JPEGLosslessHierarchical28Retired,
JPEGLosslessHierarchical29Retired,
JPEGLosslessSV1,
JPEGLSLossless,
JPEGLSNearLossless,
JPEG2000Lossless,
JPEG2000,
JPEG2000MCLossless,
JPEG2000MC,
JPIPReferenced,
JPIPReferencedDeflate,
MPEG2MPML,
MPEG2MPMLF,
MPEG2MPHL,
MPEG2MPHLF,
MPEG4HP41,
MPEG4HP41F,
MPEG4HP41BD,
MPEG4HP41BDF,
MPEG4HP422D,
MPEG4HP422DF,
MPEG4HP423D,
MPEG4HP423DF,
MPEG4HP42STEREO,
MPEG4HP42STEREOF,
HEVCMP51,
HEVCM10P51,
HTJ2KLossless,
HTJ2KLosslessRPCL,
HTJ2K,
JPIPHTJ2KReferenced,
JPIPHTJ2KReferencedDeflate,
RLELossless,
RFC2557MIMEEncapsulation,
XMLEncoding,
SMPTEST211020UncompressedProgressiveActiveVideo,
SMPTEST211020UncompressedInterlacedActiveVideo,
SMPTEST211030PCMDigitalAudio
};

//ts_=1.2.840.10008.1.2
enum ts_uidenum{
ts_papyrus3ile,
ts_,
ts_1,
ts_1_98,
ts_1_99,
ts_2,
ts_4_50,
ts_4_51,
ts_4_52,
ts_4_53,
ts_4_54,
ts_4_55,
ts_4_56,
ts_4_57,
ts_4_58,
ts_4_59,
ts_4_60,
ts_4_61,
ts_4_62,
ts_4_63,
ts_4_64,
ts_4_65,
ts_4_66,
ts_4_70,
ts_4_80,
ts_4_81,
ts_4_90,
ts_4_91,
ts_4_92,
ts_4_93,
ts_4_94,
ts_4_95,
ts_4_100,
ts_4_100_1,
ts_4_101,
ts_4_101_1,
ts_4_102,
ts_4_102_1,
ts_4_103,
ts_4_103_1,
ts_4_104,
ts_4_104_1,
ts_4_105,
ts_4_105_1,
ts_4_106,
ts_4_106_1,
ts_4_107,
ts_4_108,
ts_4_201,
ts_4_202,
ts_4_203,
ts_4_204,
ts_4_205,
ts_5,
ts_6_1,
ts_6_2,
ts_7_1,
ts_7_2,
ts_7_3
};

uint8 tsidx( uint8_t *valbytes, uint16 vallength );

NSString *tsname( uint16 tsidx);

#endif /* TransferSyntaxes_h */