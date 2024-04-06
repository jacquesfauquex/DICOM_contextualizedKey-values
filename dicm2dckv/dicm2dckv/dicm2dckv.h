//
//  dicm2mdbx.h
//  dicm2mdbx
//
//  Created by jacquesfauquex on 2024-02-28.
//#import "Repertoires.h"
#ifndef parseDICM_h
#define parseDICM_h

#import <Foundation/Foundation.h>

#import "Repertoires.h"
#import "SopClasses.h"
#import "TransferSyntaxes.h"

enum dicm2mdbxArgs{
   dicm2mdbxCmd=0,
   dicm2mdbxIn, //path or http url(://) or - (=stdin)
   dicm2mdbxOut //path to writeable dir in which shall be written uuid.bin sopuid.dcm or sopuid.dat (+ sopuid.lck)
};

static NSArray *args=nil;

struct trl {
   uint32 t;
   uint16 r;
   uint16 l;
};

struct ele {
   uint8 g;
   uint8 G;
   uint8 u;
   uint8 U;
   uint16 r;
   uint16 l;
};

struct uint64lh {
   uint32 l;
   uint32 h;
};

//returns true when it was possible to read the 8 bytes
BOOL read8bytes(
   NSInputStream *stream,
   uint8_t *buffer,
   NSInteger *bytesReadRef
);


/*
 NON RECURSIVE
 read stream up to transfer syntax.
 Valora sopclassidx
 Valora soptsidx
 Además guarda in valbytes todos los bytes leídos de tal forma a poder crear archivos .bin o .dcm
 
 returns true if next attribute is already loaded in keybytes
 */
NSString *dicmuptosopts(
  uint8_t *keybytes,     // buffer matriz de creación de nuevos keys por diferencial
  uint8_t *valbytes,     // lectura del valor del atributo returns with sopiuid
  NSInputStream *stream, // input
  uint64 *inloc,         // current stream byte index
  uint64 *soloc,         // offset in valbyes for sop class
  uint16 *solen,         // length in valbyes for sop class
  uint16 *soidx,         // index in const char *scstr[]
  uint64 *siloc,         // offset in valbyes for sop instance uid
  uint16 *silen,         // length in valbyes for sop instance uid
  uint64 *stloc,         // offset in valbyes for transfer syntax
  uint16 *stlen,         // length in valbyes for transfer syntax
  uint8  *stidx          // index in const char *csstr[]
);

/*
 RECURSIVE
 parser
 */
BOOL dicm2kvdb(
   uint8_t *keybytes,     // buffer matriz de creación de nuevos keys por diferencial
   uint8 keydepth,        // offset actual en el búfer matriz (cambia con el nivel de recursión)
   BOOL readfirstattr,    // true:read desde stream. false:ya está en keybytes
   uint16 keycs,          // key charset
   uint8_t *valbytes,     // lectura del valor del atributo
   NSInputStream *stream, // input
   uint64 *idx,           // offstet en stream
   uint32 beforebyte,     // limite superior de lectura
   uint32 beforetag,      // limite superior attr. Al salir, el attr se encuentra leido y guardado en keybytes
   id *db,                // referencia a db, o nil si no se guarda el resultado del parseo
   NSError *error         // nil o instancia de NSError creada por la subrutina
);



/*
 parseo con bitacora de tags y posiciones en stdout
 */
BOOL dicm2null(
   uint8_t *keybytes,
   BOOL readfirstattr,
   uint8_t *valbytes,
   NSInputStream *stream,
   uint64 *idx,
   BOOL basetag,
   uint32 beforebyte,
   uint32 beforetag,
   NSError *error
);


//----------------------------------
// subroutinas
//-----------------------------------


/*
 LE>BE de grupo y unidad dentro del buffer
 */
void swaptag(struct ele *a);


/*
 devuelve swap LE>BE de uint32
 */
uint32 letag(uint32 t);


/*
 devuelve LE>BE de uint 16 grupo y unidad por referencia dentro de la estructura attributo
 */
uint32 attrletag(struct ele *a);


#endif /* parseDICM_h */