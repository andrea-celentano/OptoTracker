// Generated at Fri Feb 13 19:04:53 2015. Do not modify it

/*
GCC-XML version 0.9.0
Configuration settings:
  GCCXML_CONFIG="/usr/local/share/gccxml-0.9/gccxml_config"
  GCCXML_COMPILER="/usr/bin/c++"
  GCCXML_CXXFLAGS=""
  GCCXML_EXECUTABLE="/usr/local/bin/gccxml_cc1plus"
  GCCXML_CPP="/usr/local/bin/gccxml_cc1plus"
  GCCXML_FLAGS="-D__DBL_MIN_EXP__='(-1021)' -D__FLT_MIN__='1.17549435e-38F' -D__CHAR_BIT__='8' -D__WCHAR_MAX__='2147483647' -D__DBL_DENORM_MIN__='4.9406564584124654e-324' -D__FLT_EVAL_METHOD__='0' -D__DBL_MIN_10_EXP__='(-307)' -D__FINITE_MATH_ONLY__='0' -D__LP64__='1' -D__SHRT_MAX__='32767' -D__LDBL_MAX__='1.18973149535723176502e+4932L' -D__UINTMAX_TYPE__='long unsigned int' -D__linux='1' -D__unix='1' -D__linux__='1' -D__SCHAR_MAX__='127' -D__USER_LABEL_PREFIX__='' -D__STDC_HOSTED__='1' -D__DBL_DIG__='15' -D__FLT_EPSILON__='1.19209290e-7F' -D__GXX_WEAK__='1' -D__LDBL_MIN__='3.36210314311209350626e-4932L' -D__unix__='1' -D__DECIMAL_DIG__='21' -D__gnu_linux__='1' -D__LDBL_HAS_QUIET_NAN__='1' -D__GNUC__='4' -D__MMX__='1' -D__DBL_MAX__='1.7976931348623157e+308' -D__DBL_HAS_INFINITY__='1' -D__cplusplus='1' -D__DEPRECATED='1' -D__DBL_MAX_EXP__='1024' -D__SSE2_MATH__='1' -D__amd64='1' -D__GNUG__='4' -D__LONG_LONG_MAX__='9223372036854775807LL' -D__GXX_ABI_VERSION='1002' -D__FLT_MIN_EXP__='(-125)' -D__x86_64='1' -D__DBL_MIN__='2.2250738585072014e-308' -D__FLT_MIN_10_EXP__='(-37)' -D__DBL_HAS_QUIET_NAN__='1' -D__REGISTER_PREFIX__='' -D__NO_INLINE__='1' -D__FLT_MANT_DIG__='24' -D__VERSION__='"4.1.2 20080704 (Red Hat 4.1.2-55)"' -Dunix='1' -D__SIZE_TYPE__='long unsigned int' -D__ELF__='1' -D__FLT_RADIX__='2' -D__LDBL_EPSILON__='1.08420217248550443401e-19L' -D__GNUC_RH_RELEASE__='55' -D__k8='1' -D__LDBL_DIG__='18' -D__x86_64__='1' -D__FLT_HAS_QUIET_NAN__='1' -D__FLT_MAX_10_EXP__='38' -D__LONG_MAX__='9223372036854775807L' -D__FLT_HAS_INFINITY__='1' -Dlinux='1' -D__EXCEPTIONS='1' -D__LDBL_MANT_DIG__='64' -D__k8__='1' -D__WCHAR_TYPE__='int' -D__FLT_DIG__='6' -D__INT_MAX__='2147483647' -D__FLT_MAX_EXP__='128' -D__DBL_MANT_DIG__='53' -D__WINT_TYPE__='unsigned int' -D__SSE__='1' -D__LDBL_MIN_EXP__='(-16381)' -D__amd64__='1' -D__LDBL_MAX_EXP__='16384' -D__LDBL_MAX_10_EXP__='4932' -D__DBL_EPSILON__='2.2204460492503131e-16' -D_LP64='1' -D__GNUC_PATCHLEVEL__='2' -D__LDBL_HAS_INFINITY__='1' -D__INTMAX_MAX__='9223372036854775807L' -D__FLT_DENORM_MIN__='1.40129846e-45F' -D__FLT_MAX__='3.40282347e+38F' -D__SSE2__='1' -D__INTMAX_TYPE__='long int' -D__GNUC_MINOR__='1' -D__DBL_MAX_10_EXP__='308' -D__LDBL_DENORM_MIN__='3.64519953188247460253e-4951L' -D__STDC__='1' -D__PTRDIFF_TYPE__='long int' -D__LDBL_MIN_10_EXP__='(-4931)' -D__SSE_MATH__='1' -D__GNUC_GNU_INLINE__='1' -D_GNU_SOURCE='1' -iwrapper"/usr/local/share/gccxml-0.9/GCC/4.1" -isystem"/usr/lib/gcc/x86_64-redhat-linux/4.1.2/../../../../include/c++/4.1.2" -isystem"/usr/lib/gcc/x86_64-redhat-linux/4.1.2/../../../../include/c++/4.1.2/x86_64-redhat-linux" -isystem"/usr/lib/gcc/x86_64-redhat-linux/4.1.2/../../../../include/c++/4.1.2/backward" -isystem"/usr/local/include" -isystem"/usr/lib/gcc/x86_64-redhat-linux/4.1.2/include" -isystem"/usr/include" -include "gccxml_builtins.h""
  GCCXML_USER_FLAGS=""
  GCCXML_ROOT="/usr/local/share/gccxml-0.9"

Compiler info:
c++ (GCC) 4.1.2 20080704 (Red Hat 4.1.2-55)
Copyright (C) 2006 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifdef _WIN32
#pragma warning ( disable : 4786 )
#pragma warning ( disable : 4345 )
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3)) && !defined(__INTEL_COMPILER) 
# pragma GCC diagnostic ignored "-Warray-bounds"
#endif
#include "/project/Gruppo3/fiber5/celentano/OptoTracker/sim/OpNovice_old/include/OpNoviceClasses.hh"
#ifdef CONST
# undef CONST
#endif
#include "Reflex/Builder/ReflexBuilder.h"
#include <typeinfo>

namespace {
  ::Reflex::NamespaceBuilder nsb0( Reflex::Literal("std") );
  ::Reflex::NamespaceBuilder nsb1( Reflex::Literal("CLHEP") );
  ::Reflex::Type type_43 = ::Reflex::TypeBuilder(Reflex::Literal("int"));
  ::Reflex::Type type_30 = ::Reflex::TypeBuilder(Reflex::Literal("long"));
  ::Reflex::Type type_686 = ::Reflex::TypeBuilder(Reflex::Literal("void"));
  ::Reflex::Type type_898 = ::Reflex::TypeBuilder(Reflex::Literal("bool"));
  ::Reflex::Type type_302 = ::Reflex::TypeBuilder(Reflex::Literal("char"));
  ::Reflex::Type type_void = ::Reflex::TypeBuilder(Reflex::Literal("void"));
  ::Reflex::Type type_355 = ::Reflex::TypeBuilder(Reflex::Literal("double"));
  ::Reflex::Type type_944 = ::Reflex::TypeBuilder(Reflex::Literal("G4VDigi"));
  ::Reflex::Type type_1000 = ::Reflex::TypeBuilder(Reflex::Literal("G4VHit"));
  ::Reflex::Type type_2064 = ::Reflex::TypeBuilder(Reflex::Literal("G4String"));
  ::Reflex::Type type_448 = ::Reflex::TypeBuilder(Reflex::Literal("OpNoviceDigi"));
  ::Reflex::Type type_33 = ::Reflex::TypeBuilder(Reflex::Literal("unsigned long"));
  ::Reflex::Type type_1621 = ::Reflex::TypeBuilder(Reflex::Literal("G4SubString"));
  ::Reflex::Type type_199 = ::Reflex::TypeBuilder(Reflex::Literal("unsigned int"));
  ::Reflex::Type type_1537 = ::Reflex::TypeBuilder(Reflex::Literal("OpNovicePMTHit"));
  ::Reflex::Type type_1256 = ::Reflex::TypeBuilder(Reflex::Literal("G4VPhysicalVolume"));
  ::Reflex::Type type_1335 = ::Reflex::TypeBuilder(Reflex::Literal("CLHEP::Hep3Vector"));
  ::Reflex::Type type_1989 = ::Reflex::TypeBuilder(Reflex::Literal("CLHEP::HepRotation"));
  ::Reflex::Type type_4381 = ::Reflex::TypeBuilder(Reflex::Literal("CLHEP::HepAxisAngle"));
  ::Reflex::Type type_2248 = ::Reflex::TypeBuilder(Reflex::Literal("std::vector<double>"));
  ::Reflex::Type type_2409 = ::Reflex::TypeBuilder(Reflex::Literal("std::allocator<char>"));
  ::Reflex::Type type_4446 = ::Reflex::TypeBuilder(Reflex::Literal("CLHEP::HepEulerAngles"));
  ::Reflex::Type type_2458 = ::Reflex::TypeBuilder(Reflex::Literal("std::char_traits<char>"));
  ::Reflex::Type type_2247 = ::Reflex::TypeBuilder(Reflex::Literal("std::vector<G4AttValue>"));
  ::Reflex::Type type_2265 = ::Reflex::TypeBuilder(Reflex::Literal("std::basic_string<char>"));
  ::Reflex::Type type_5148 = ::Reflex::EnumTypeBuilder(Reflex::Literal("G4String::caseCompare"));
  ::Reflex::Type type_2245 = ::Reflex::TypeBuilder(Reflex::Literal("std::vector<OpNoviceDigi*>"));
  ::Reflex::Type type_2158 = ::Reflex::TypeBuilder(Reflex::Literal("std::map<G4String,G4AttDef>"));
  ::Reflex::Type type_2246 = ::Reflex::TypeBuilder(Reflex::Literal("std::vector<OpNovicePMTHit*>"));
  ::Reflex::Type type_2397 = ::Reflex::TypeBuilder(Reflex::Literal("std::allocator<OpNoviceDigi*>"));
  ::Reflex::Type type_2398 = ::Reflex::TypeBuilder(Reflex::Literal("std::allocator<OpNovicePMTHit*>"));
  ::Reflex::Type type_7164 = ::Reflex::TypeBuilder(Reflex::Literal("std::basic_string<char>::_Alloc_hider"));
  ::Reflex::Type type_185 = ::Reflex::TypeBuilder(Reflex::Literal("std::basic_istream<char,std::char_traits<char> >"));
  ::Reflex::Type type_3167 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >"));
  ::Reflex::Type type_2603 = ::Reflex::TypeBuilder(Reflex::Literal("std::_Vector_base<OpNoviceDigi*,std::allocator<OpNoviceDigi*> >"));
  ::Reflex::Type type_3170 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >"));
  ::Reflex::Type type_2604 = ::Reflex::TypeBuilder(Reflex::Literal("std::_Vector_base<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> >"));
  ::Reflex::Type type_3151 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >"));
  ::Reflex::Type type_3153 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >"));
  ::Reflex::Type type_3152 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<OpNoviceDigi* const*,std::vector<OpNoviceDigi*> >"));
  ::Reflex::Type type_3154 = ::Reflex::TypeBuilder(Reflex::Literal("__gnu_cxx::__normal_iterator<OpNovicePMTHit* const*,std::vector<OpNovicePMTHit*> >"));
  ::Reflex::Type type_2529 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<char*,std::basic_string<char> > >"));
  ::Reflex::Type type_2528 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> > >"));
  ::Reflex::Type type_2507 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> > >"));
  ::Reflex::Type type_2509 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> > >"));
  ::Reflex::Type type_2506 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<OpNoviceDigi* const*,std::vector<OpNoviceDigi*> > >"));
  ::Reflex::Type type_2508 = ::Reflex::TypeBuilder(Reflex::Literal("std::reverse_iterator<__gnu_cxx::__normal_iterator<OpNovicePMTHit* const*,std::vector<OpNovicePMTHit*> > >"));
  ::Reflex::Type type_211 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("G4int"), type_43);
  ::Reflex::Type type_1353 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("G4double"), type_355);
  ::Reflex::Type type_6509 = ::Reflex::PointerBuilder(type_1256);
  ::Reflex::Type type_448c = ::Reflex::ConstBuilder(type_448);
  ::Reflex::Type type_4759 = ::Reflex::ReferenceBuilder(type_448c);
  ::Reflex::Type type_240 = ::Reflex::PointerBuilder(type_686);
  ::Reflex::Type type_1343 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("size_t"), type_33);
  ::Reflex::Type type_9830 = ::Reflex::ReferenceBuilder(type_944);
  ::Reflex::Type type_944c = ::Reflex::ConstBuilder(type_944);
  ::Reflex::Type type_9831 = ::Reflex::ReferenceBuilder(type_944c);
  ::Reflex::Type type_2158c = ::Reflex::ConstBuilder(type_2158);
  ::Reflex::Type type_9832 = ::Reflex::PointerBuilder(type_2158c);
  ::Reflex::Type type_9833 = ::Reflex::PointerBuilder(type_2247);
  ::Reflex::Type type_9964 = ::Reflex::ReferenceBuilder(type_1000);
  ::Reflex::Type type_1000c = ::Reflex::ConstBuilder(type_1000);
  ::Reflex::Type type_9965 = ::Reflex::ReferenceBuilder(type_1000c);
  ::Reflex::Type type_1335c = ::Reflex::ConstBuilder(type_1335);
  ::Reflex::Type type_9976 = ::Reflex::ReferenceBuilder(type_1335c);
  ::Reflex::Type type_6756 = ::Reflex::ReferenceBuilder(type_355);
  ::Reflex::Type type_10283 = ::Reflex::ReferenceBuilder(type_1335);
  ::Reflex::Type type_1989c = ::Reflex::ConstBuilder(type_1989);
  ::Reflex::Type type_10284 = ::Reflex::ReferenceBuilder(type_1989c);
  ::Reflex::Type type_4381c = ::Reflex::ConstBuilder(type_4381);
  ::Reflex::Type type_10285 = ::Reflex::ReferenceBuilder(type_4381c);
  ::Reflex::Type type_4446c = ::Reflex::ConstBuilder(type_4446);
  ::Reflex::Type type_10286 = ::Reflex::ReferenceBuilder(type_4446c);
  ::Reflex::Type type_1908 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("G4bool"), type_898);
  ::Reflex::Type type_1537c = ::Reflex::ConstBuilder(type_1537);
  ::Reflex::Type type_4815 = ::Reflex::ReferenceBuilder(type_1537c);
  ::Reflex::Type type_2279 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("std::string"), type_2265);
  ::Reflex::Type type_302c = ::Reflex::ConstBuilder(type_302);
  ::Reflex::Type type_2727 = ::Reflex::PointerBuilder(type_302c);
  ::Reflex::Type type_451 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("str_size"), type_1343);
  ::Reflex::Type type_2064c = ::Reflex::ConstBuilder(type_2064);
  ::Reflex::Type type_9784 = ::Reflex::ReferenceBuilder(type_2064c);
  ::Reflex::Type type_1621c = ::Reflex::ConstBuilder(type_1621);
  ::Reflex::Type type_10872 = ::Reflex::ReferenceBuilder(type_1621c);
  ::Reflex::Type type_2279c = ::Reflex::ConstBuilder(type_2279);
  ::Reflex::Type type_8626 = ::Reflex::ReferenceBuilder(type_2279c);
  ::Reflex::Type type_10874 = ::Reflex::ReferenceBuilder(type_2064);
  ::Reflex::Type type_6588 = ::Reflex::ReferenceBuilder(type_302);
  ::Reflex::Type type_7154 = ::Reflex::ReferenceBuilder(type_302c);
  ::Reflex::Type type_186 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("std::istream"), type_185);
  ::Reflex::Type type_10176 = ::Reflex::ReferenceBuilder(type_186);
  ::Reflex::Type type_4753 = ::Reflex::PointerBuilder(type_448);
  ::Reflex::Type type_6631 = ::Reflex::PointerBuilder(type_4753);
  ::Reflex::Type type_4753c = ::Reflex::ConstBuilder(type_4753);
  ::Reflex::Type type_6633 = ::Reflex::PointerBuilder(type_4753c);
  ::Reflex::Type type_6635 = ::Reflex::ReferenceBuilder(type_4753);
  ::Reflex::Type type_6637 = ::Reflex::ReferenceBuilder(type_4753c);
  ::Reflex::Type type_1043 = ::Reflex::TypedefTypeBuilder(Reflex::Literal("ptrdiff_t"), type_30);
  ::Reflex::Type type_2397c = ::Reflex::ConstBuilder(type_2397);
  ::Reflex::Type type_11143 = ::Reflex::ReferenceBuilder(type_2397c);
  ::Reflex::Type type_2245c = ::Reflex::ConstBuilder(type_2245);
  ::Reflex::Type type_11144 = ::Reflex::ReferenceBuilder(type_2245c);
  ::Reflex::Type type_11145 = ::Reflex::ReferenceBuilder(type_2245);
  ::Reflex::Type type_4809 = ::Reflex::PointerBuilder(type_1537);
  ::Reflex::Type type_6692 = ::Reflex::PointerBuilder(type_4809);
  ::Reflex::Type type_4809c = ::Reflex::ConstBuilder(type_4809);
  ::Reflex::Type type_6694 = ::Reflex::PointerBuilder(type_4809c);
  ::Reflex::Type type_6696 = ::Reflex::ReferenceBuilder(type_4809);
  ::Reflex::Type type_6698 = ::Reflex::ReferenceBuilder(type_4809c);
  ::Reflex::Type type_2398c = ::Reflex::ConstBuilder(type_2398);
  ::Reflex::Type type_11147 = ::Reflex::ReferenceBuilder(type_2398c);
  ::Reflex::Type type_2246c = ::Reflex::ConstBuilder(type_2246);
  ::Reflex::Type type_11148 = ::Reflex::ReferenceBuilder(type_2246c);
  ::Reflex::Type type_11149 = ::Reflex::ReferenceBuilder(type_2246);
  ::Reflex::Type type_724 = ::Reflex::PointerBuilder(type_302);
  ::Reflex::Type type_2409c = ::Reflex::ConstBuilder(type_2409);
  ::Reflex::Type type_11214 = ::Reflex::ReferenceBuilder(type_2409c);
  ::Reflex::Type type_2265c = ::Reflex::ConstBuilder(type_2265);
  ::Reflex::Type type_8771 = ::Reflex::ReferenceBuilder(type_2265c);
  ::Reflex::Type type_8639 = ::Reflex::ReferenceBuilder(type_2265);
} // unnamed namespace

#ifndef __CINT__

// Shadow classes to obtain the data member offsets 
namespace __shadow__ {
#ifdef __OpNoviceDigi
#undef __OpNoviceDigi
#endif
class __OpNoviceDigi : public ::G4VDigi {
  public:
  __OpNoviceDigi();
  virtual ~__OpNoviceDigi() throw();
  ::G4int fPmtNumber;
  ::G4int fNPixels;
  ::G4String fName;
  ::G4double fXmax;
  ::G4double fYmax;
  ::G4int fPhotons;
  ::G4double fFirstTime;
  void* fPhysVolMother;
  void* fPhysVol;
};
#ifdef __G4VDigi
#undef __G4VDigi
#endif
class __G4VDigi {
  public:
  __G4VDigi();
  virtual ~__G4VDigi() throw();
};
#ifdef __G4VHit
#undef __G4VHit
#endif
class __G4VHit {
  public:
  __G4VHit();
  virtual ~__G4VHit() throw();
};
#ifdef __CLHEP__Hep3Vector
#undef __CLHEP__Hep3Vector
#endif
class __CLHEP__Hep3Vector {
  public:
  __CLHEP__Hep3Vector();
  double dx;
  double dy;
  double dz;
};
#ifdef __OpNovicePMTHit
#undef __OpNovicePMTHit
#endif
class __OpNovicePMTHit : public ::G4VHit {
  public:
  __OpNovicePMTHit();
  virtual ~__OpNovicePMTHit() throw();
  ::G4int fPmtNumber;
  ::G4int fPhotons;
  ::G4int fNPixels;
  ::G4double fFirstTime;
  ::G4String fName;
  ::std::vector<double> fTime;
  ::std::vector<double> fEnergy;
  ::std::vector<double> fX;
  ::std::vector<double> fY;
  void* fPhysVolMother;
  void* fPhysVol;
  ::G4bool fDrawit;
  ::G4int fDrawScaleMin;
  ::G4int fDrawScaleMax;
};
#ifdef __G4String
#undef __G4String
#endif
class __G4String : public ::std::basic_string<char> {
  public:
  __G4String();
};
#ifdef __std__vector_OpNoviceDigip_
#undef __std__vector_OpNoviceDigip_
#endif
class __std__vector_OpNoviceDigip_ : protected ::std::_Vector_base<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > {
  public:
  __std__vector_OpNoviceDigip_();
};
#ifdef __std__vector_OpNovicePMTHitp_
#undef __std__vector_OpNovicePMTHitp_
#endif
class __std__vector_OpNovicePMTHitp_ : protected ::std::_Vector_base<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > {
  public:
  __std__vector_OpNovicePMTHitp_();
};
#ifdef __std__basic_string_char_
#undef __std__basic_string_char_
#endif
struct __std__basic_string_char_ {
  public:
  __std__basic_string_char_();
#ifdef __std__basic_string_char____Rep_base
#undef __std__basic_string_char____Rep_base
#endif
  struct __std__basic_string_char____Rep_base {
    public:
    __std__basic_string_char____Rep_base();
    ::size_t _M_length;
    ::size_t _M_capacity;
    ::_Atomic_word _M_refcount;
  };
#ifdef __std__basic_string_char____Rep
#undef __std__basic_string_char____Rep
#endif
  struct __std__basic_string_char____Rep :   public __std__basic_string_char____Rep_base   {
    public:
    __std__basic_string_char____Rep();
  };
#ifdef __std__basic_string_char____Alloc_hider
#undef __std__basic_string_char____Alloc_hider
#endif
  struct __std__basic_string_char____Alloc_hider :   public ::std::allocator<char>   {
    public:
    __std__basic_string_char____Alloc_hider();
    void* _M_p;
  };
  __std__basic_string_char____Alloc_hider _M_dataplus;
};
}


#endif // __CINT__
namespace {
//------Stub functions for class OpNoviceDigi -------------------------------
static void constructor_3180( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::OpNoviceDigi();
  else ::new(mem) ::OpNoviceDigi();
}

static void constructor_3181( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::OpNoviceDigi(*(::G4String*)arg[0]);
  else ::new(mem) ::OpNoviceDigi(*(::G4String*)arg[0]);
}

static void destructor_3182(void*, void * o, const std::vector<void*>&, void *) {
(((::OpNoviceDigi*)o)->::OpNoviceDigi::~OpNoviceDigi)();
}
static void constructor_3183( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::OpNoviceDigi(*(const ::OpNoviceDigi*)arg[0]);
  else ::new(mem) ::OpNoviceDigi(*(const ::OpNoviceDigi*)arg[0]);
}

static  void operator_3184( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::OpNoviceDigi*)o)->operator=)(*(const ::OpNoviceDigi*)arg[0]);
  else   (((::OpNoviceDigi*)o)->operator=)(*(const ::OpNoviceDigi*)arg[0]);
}

static  void operator_3185( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::OpNoviceDigi*)o)->operator==)(*(const ::OpNoviceDigi*)arg[0]));
  else   (((const ::OpNoviceDigi*)o)->operator==)(*(const ::OpNoviceDigi*)arg[0]);
}

static  void operator_3186( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNoviceDigi*)o)->operator new)(*(::size_t*)arg[0]));
  else   (((::OpNoviceDigi*)o)->operator new)(*(::size_t*)arg[0]);
}

static  void operator_3187( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->operator delete)((void*)arg[0]);
}

static  void method_3188( void*, void* o, const std::vector<void*>&, void*)
{
  (((::OpNoviceDigi*)o)->Draw)();
}

static  void method_3189( void*, void* o, const std::vector<void*>&, void*)
{
  (((::OpNoviceDigi*)o)->Print)();
}

static  void method_3190( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetPMTNumber)(*(::G4int*)arg[0]);
}

static  void method_3191( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNoviceDigi*)o)->GetPMTNumber)());
  else   (((::OpNoviceDigi*)o)->GetPMTNumber)();
}

static  void method_3192( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetNPixels)(*(::G4int*)arg[0]);
}

static  void method_3193( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNoviceDigi*)o)->GetNPixels)());
  else   (((::OpNoviceDigi*)o)->GetNPixels)();
}

static  void method_3194( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetPhotonsNumber)(*(::G4int*)arg[0]);
}

static  void method_3195( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNoviceDigi*)o)->GetPhotonsNumber)());
  else   (((::OpNoviceDigi*)o)->GetPhotonsNumber)();
}

static  void method_3196( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetPMTPhysVol)((::G4VPhysicalVolume*)arg[0]);
}

static  void method_3197( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNoviceDigi*)o)->GetPMTPhysVol)());
  else   (((::OpNoviceDigi*)o)->GetPMTPhysVol)();
}

static  void method_3198( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetPMTPhysVolMother)((::G4VPhysicalVolume*)arg[0]);
}

static  void method_3199( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNoviceDigi*)o)->GetPMTPhysVolMother)());
  else   (((::OpNoviceDigi*)o)->GetPMTPhysVolMother)();
}

static  void method_3200( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNoviceDigi*)o)->SetName)(*(::G4String*)arg[0]);
}

static  void method_3201( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4String)((((::OpNoviceDigi*)o)->GetName)());
  else   (((::OpNoviceDigi*)o)->GetName)();
}

static void method_newdel_448( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::OpNoviceDigi >::new_np_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::OpNoviceDigi >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::OpNoviceDigi >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::OpNoviceDigi >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::OpNoviceDigi >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

static void method_x1( void* retaddr, void*, const std::vector<void*>&, void*)
{
  typedef std::vector<std::pair< ::Reflex::Base, int> > Bases_t;
  static Bases_t s_bases;
  if ( !s_bases.size() ) {
    s_bases.push_back(std::make_pair(::Reflex::Base( ::Reflex::TypeBuilder(Reflex::Literal("G4VDigi")), ::Reflex::BaseOffset< ::OpNoviceDigi,::G4VDigi >::Get(),::Reflex::PUBLIC), 0));
  }
  if (retaddr) *(Bases_t**)retaddr = &s_bases;
}

//------Dictionary for class OpNoviceDigi -------------------------------
void __OpNoviceDigi_db_datamem(Reflex::Class*);
void __OpNoviceDigi_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __OpNoviceDigi_datamem_bld(&__OpNoviceDigi_db_datamem);
Reflex::GenreflexMemberBuilder __OpNoviceDigi_funcmem_bld(&__OpNoviceDigi_db_funcmem);
void __OpNoviceDigi_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("OpNoviceDigi"), typeid(::OpNoviceDigi), sizeof(::OpNoviceDigi), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::VIRTUAL, ::Reflex::CLASS)
  .AddBase(type_944, ::Reflex::BaseOffset< ::OpNoviceDigi, ::G4VDigi >::Get(), ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("OpNoviceDigi"), constructor_3180, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_2064), Reflex::Literal("OpNoviceDigi"), constructor_3181, 0, "", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~OpNoviceDigi"), destructor_3182, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::DESTRUCTOR )
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_4759), Reflex::Literal("OpNoviceDigi"), constructor_3183, 0, "", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_448, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getBasesTable"), method_x1, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandDataMemberBuilder(&__OpNoviceDigi_datamem_bld)
  .AddOnDemandFunctionMemberBuilder(&__OpNoviceDigi_funcmem_bld);
}

//------Delayed data member builder for class OpNoviceDigi -------------------
void __OpNoviceDigi_db_datamem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddDataMember(type_211, Reflex::Literal("fPmtNumber"), OffsetOf(__shadow__::__OpNoviceDigi, fPmtNumber), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fNPixels"), OffsetOf(__shadow__::__OpNoviceDigi, fNPixels), ::Reflex::PRIVATE)
  .AddDataMember(type_2064, Reflex::Literal("fName"), OffsetOf(__shadow__::__OpNoviceDigi, fName), ::Reflex::PRIVATE)
  .AddDataMember(type_1353, Reflex::Literal("fXmax"), OffsetOf(__shadow__::__OpNoviceDigi, fXmax), ::Reflex::PRIVATE)
  .AddDataMember(type_1353, Reflex::Literal("fYmax"), OffsetOf(__shadow__::__OpNoviceDigi, fYmax), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fPhotons"), OffsetOf(__shadow__::__OpNoviceDigi, fPhotons), ::Reflex::PRIVATE)
  .AddDataMember(type_1353, Reflex::Literal("fFirstTime"), OffsetOf(__shadow__::__OpNoviceDigi, fFirstTime), ::Reflex::PRIVATE)
  .AddDataMember(type_6509, Reflex::Literal("fPhysVolMother"), OffsetOf(__shadow__::__OpNoviceDigi, fPhysVolMother), ::Reflex::PRIVATE | ::Reflex::TRANSIENT)
  .AddDataMember(type_6509, Reflex::Literal("fPhysVol"), OffsetOf(__shadow__::__OpNoviceDigi, fPhysVol), ::Reflex::PRIVATE | ::Reflex::TRANSIENT);
}
//------Delayed function member builder for class OpNoviceDigi -------------------
void __OpNoviceDigi_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_4759, type_4759), Reflex::Literal("operator="), operator_3184, 0, "", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_4759), Reflex::Literal("operator=="), operator_3185, 0, "", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_240, type_1343), Reflex::Literal("operator new"), operator_3186, 0, "", ::Reflex::PUBLIC | ::Reflex::STATIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_240), Reflex::Literal("operator delete"), operator_3187, 0, "aDigi", ::Reflex::PUBLIC | ::Reflex::STATIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Draw"), method_3188, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Print"), method_3189, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetPMTNumber"), method_3190, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetPMTNumber"), method_3191, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetNPixels"), method_3192, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetNPixels"), method_3193, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetPhotonsNumber"), method_3194, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetPhotonsNumber"), method_3195, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6509), Reflex::Literal("SetPMTPhysVol"), method_3196, 0, "physVol", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6509), Reflex::Literal("GetPMTPhysVol"), method_3197, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6509), Reflex::Literal("SetPMTPhysVolMother"), method_3198, 0, "physVol", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6509), Reflex::Literal("GetPMTPhysVolMother"), method_3199, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_2064), Reflex::Literal("SetName"), method_3200, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2064), Reflex::Literal("GetName"), method_3201, 0, 0, ::Reflex::PUBLIC);
}
//------Stub functions for class G4VDigi -------------------------------
static  void operator_3615( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4VDigi*)o)->operator=)(*(const ::G4VDigi*)arg[0]);
  else   (((::G4VDigi*)o)->operator=)(*(const ::G4VDigi*)arg[0]);
}

static void constructor_3616( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4VDigi(*(const ::G4VDigi*)arg[0]);
  else ::new(mem) ::G4VDigi(*(const ::G4VDigi*)arg[0]);
}

static void constructor_3617( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4VDigi();
  else ::new(mem) ::G4VDigi();
}

static void destructor_3618(void*, void * o, const std::vector<void*>&, void *) {
(((::G4VDigi*)o)->::G4VDigi::~G4VDigi)();
}
static  void operator_3619( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::G4VDigi*)o)->operator==)(*(const ::G4VDigi*)arg[0]));
  else   (((const ::G4VDigi*)o)->operator==)(*(const ::G4VDigi*)arg[0]);
}

static  void method_3620( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4VDigi*)o)->Draw)();
}

static  void method_3621( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4VDigi*)o)->Print)();
}

static  void method_3622( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4VDigi*)o)->GetAttDefs)());
  else   (((const ::G4VDigi*)o)->GetAttDefs)();
}

static  void method_3623( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4VDigi*)o)->CreateAttValues)());
  else   (((const ::G4VDigi*)o)->CreateAttValues)();
}

static void method_newdel_944( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::G4VDigi >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::G4VDigi >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::G4VDigi >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::G4VDigi >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::G4VDigi >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

//------Dictionary for class G4VDigi -------------------------------
void __G4VDigi_db_datamem(Reflex::Class*);
void __G4VDigi_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __G4VDigi_datamem_bld(&__G4VDigi_db_datamem);
Reflex::GenreflexMemberBuilder __G4VDigi_funcmem_bld(&__G4VDigi_db_funcmem);
void __G4VDigi_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("G4VDigi"), typeid(::G4VDigi), sizeof(::G4VDigi), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::VIRTUAL, ::Reflex::CLASS)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9830, type_9831), Reflex::Literal("operator="), operator_3615, 0, "", ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_9831), Reflex::Literal("G4VDigi"), constructor_3616, 0, "", ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("G4VDigi"), constructor_3617, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~G4VDigi"), destructor_3618, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::DESTRUCTOR )
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_944, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandFunctionMemberBuilder(&__G4VDigi_funcmem_bld);
}

//------Delayed data member builder for class G4VDigi -------------------
void __G4VDigi_db_datamem(Reflex::Class*) {

}
//------Delayed function member builder for class G4VDigi -------------------
void __G4VDigi_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_9831), Reflex::Literal("operator=="), operator_3619, 0, "right", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Draw"), method_3620, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Print"), method_3621, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9832), Reflex::Literal("GetAttDefs"), method_3622, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9833), Reflex::Literal("CreateAttValues"), method_3623, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::CONST);
}
//------Stub functions for class G4VHit -------------------------------
static  void operator_3734( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4VHit*)o)->operator=)(*(const ::G4VHit*)arg[0]);
  else   (((::G4VHit*)o)->operator=)(*(const ::G4VHit*)arg[0]);
}

static void constructor_3735( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4VHit(*(const ::G4VHit*)arg[0]);
  else ::new(mem) ::G4VHit(*(const ::G4VHit*)arg[0]);
}

static void constructor_3736( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4VHit();
  else ::new(mem) ::G4VHit();
}

static void destructor_3737(void*, void * o, const std::vector<void*>&, void *) {
(((::G4VHit*)o)->::G4VHit::~G4VHit)();
}
static  void operator_3738( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::G4VHit*)o)->operator==)(*(const ::G4VHit*)arg[0]));
  else   (((const ::G4VHit*)o)->operator==)(*(const ::G4VHit*)arg[0]);
}

static  void method_3739( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4VHit*)o)->Draw)();
}

static  void method_3740( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4VHit*)o)->Print)();
}

static  void method_3741( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4VHit*)o)->GetAttDefs)());
  else   (((const ::G4VHit*)o)->GetAttDefs)();
}

static  void method_3742( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4VHit*)o)->CreateAttValues)());
  else   (((const ::G4VHit*)o)->CreateAttValues)();
}

static void method_newdel_1000( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::G4VHit >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::G4VHit >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::G4VHit >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::G4VHit >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::G4VHit >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

//------Dictionary for class G4VHit -------------------------------
void __G4VHit_db_datamem(Reflex::Class*);
void __G4VHit_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __G4VHit_datamem_bld(&__G4VHit_db_datamem);
Reflex::GenreflexMemberBuilder __G4VHit_funcmem_bld(&__G4VHit_db_funcmem);
void __G4VHit_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("G4VHit"), typeid(::G4VHit), sizeof(::G4VHit), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::VIRTUAL, ::Reflex::CLASS)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9964, type_9965), Reflex::Literal("operator="), operator_3734, 0, "", ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_9965), Reflex::Literal("G4VHit"), constructor_3735, 0, "", ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("G4VHit"), constructor_3736, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~G4VHit"), destructor_3737, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::DESTRUCTOR )
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_1000, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandFunctionMemberBuilder(&__G4VHit_funcmem_bld);
}

//------Delayed data member builder for class G4VHit -------------------
void __G4VHit_db_datamem(Reflex::Class*) {

}
//------Delayed function member builder for class G4VHit -------------------
void __G4VHit_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_9965), Reflex::Literal("operator=="), operator_3738, 0, "right", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Draw"), method_3739, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Print"), method_3740, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9832), Reflex::Literal("GetAttDefs"), method_3741, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_9833), Reflex::Literal("CreateAttValues"), method_3742, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::CONST);
}
//------Stub functions for class Hep3Vector -------------------------------
static void constructor_4201( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::CLHEP::Hep3Vector();
  else ::new(mem) ::CLHEP::Hep3Vector();
}

static void constructor_4202( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0]);
  else ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0]);
}

static void constructor_4203( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0],
      *(double*)arg[1]);
  else ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0],
      *(double*)arg[1]);
}

static void constructor_4204( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0],
      *(double*)arg[1],
      *(double*)arg[2]);
  else ::new(mem) ::CLHEP::Hep3Vector(*(double*)arg[0],
      *(double*)arg[1],
      *(double*)arg[2]);
}

static void constructor_4205( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::CLHEP::Hep3Vector(*(const ::CLHEP::Hep3Vector*)arg[0]);
  else ::new(mem) ::CLHEP::Hep3Vector(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static void destructor_4206(void*, void * o, const std::vector<void*>&, void *) {
(((::CLHEP::Hep3Vector*)o)->::CLHEP::Hep3Vector::~Hep3Vector)();
}
static  void operator_4207( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->operator())(*(int*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator())(*(int*)arg[0]);
}

static  void operator_4208( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->operator[])(*(int*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator[])(*(int*)arg[0]);
}

static  void operator_4209( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator())(*(int*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator())(*(int*)arg[0]);
}

static  void operator_4210( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator[])(*(int*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator[])(*(int*)arg[0]);
}

static  void method_4211( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->x)());
  else   (((const ::CLHEP::Hep3Vector*)o)->x)();
}

static  void method_4212( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->y)());
  else   (((const ::CLHEP::Hep3Vector*)o)->y)();
}

static  void method_4213( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->z)());
  else   (((const ::CLHEP::Hep3Vector*)o)->z)();
}

static  void method_4214( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setX)(*(double*)arg[0]);
}

static  void method_4215( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setY)(*(double*)arg[0]);
}

static  void method_4216( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setZ)(*(double*)arg[0]);
}

static  void method_4217( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->set)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4218( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->phi)());
  else   (((const ::CLHEP::Hep3Vector*)o)->phi)();
}

static  void method_4219( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->theta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->theta)();
}

static  void method_4220( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->cosTheta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->cosTheta)();
}

static  void method_4221( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->cos2Theta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->cos2Theta)();
}

static  void method_4222( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->mag2)());
  else   (((const ::CLHEP::Hep3Vector*)o)->mag2)();
}

static  void method_4223( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->mag)());
  else   (((const ::CLHEP::Hep3Vector*)o)->mag)();
}

static  void method_4224( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setPhi)(*(double*)arg[0]);
}

static  void method_4225( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setTheta)(*(double*)arg[0]);
}

static  void method_4226( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setMag)(*(double*)arg[0]);
}

static  void method_4227( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->perp2)());
  else   (((const ::CLHEP::Hep3Vector*)o)->perp2)();
}

static  void method_4228( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->perp)());
  else   (((const ::CLHEP::Hep3Vector*)o)->perp)();
}

static  void method_4229( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setPerp)(*(double*)arg[0]);
}

static  void method_4230( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setCylTheta)(*(double*)arg[0]);
}

static  void method_4231( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->perp2)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->perp2)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4232( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->perp)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->perp)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4233( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4234( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator==)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator==)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4235( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator!=)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator!=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4236( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isNear)(*(const ::CLHEP::Hep3Vector*)arg[0]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isNear)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isNear)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isNear)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]);
  }
}

static  void method_4237( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->howNear)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->howNear)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4238( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->deltaR)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->deltaR)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4239( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator+=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator+=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4240( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator-=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator-=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4241( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->operator-)());
  else   (((const ::CLHEP::Hep3Vector*)o)->operator-)();
}

static  void operator_4242( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator*=)(*(double*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator*=)(*(double*)arg[0]);
}

static  void operator_4243( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator/=)(*(double*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator/=)(*(double*)arg[0]);
}

static  void method_4244( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->unit)());
  else   (((const ::CLHEP::Hep3Vector*)o)->unit)();
}

static  void method_4245( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->orthogonal)());
  else   (((const ::CLHEP::Hep3Vector*)o)->orthogonal)();
}

static  void method_4246( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->dot)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->dot)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4247( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->cross)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->cross)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4248( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->angle)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->angle)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4249( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->pseudoRapidity)());
  else   (((const ::CLHEP::Hep3Vector*)o)->pseudoRapidity)();
}

static  void method_4250( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setEta)(*(double*)arg[0]);
}

static  void method_4251( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setCylEta)(*(double*)arg[0]);
}

static  void method_4252( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotateX)(*(double*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotateX)(*(double*)arg[0]);
}

static  void method_4253( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotateY)(*(double*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotateY)(*(double*)arg[0]);
}

static  void method_4254( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotateZ)(*(double*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotateZ)(*(double*)arg[0]);
}

static  void method_4255( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotateUz)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotateUz)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4256( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotate)(*(double*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]);
  else   (((::CLHEP::Hep3Vector*)o)->rotate)(*(double*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]);
}

static  void operator_4257( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->operator*=)(*(const ::CLHEP::HepRotation*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->operator*=)(*(const ::CLHEP::HepRotation*)arg[0]);
}

static  void method_4258( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->transform)(*(const ::CLHEP::HepRotation*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->transform)(*(const ::CLHEP::HepRotation*)arg[0]);
}

static  void method_4259( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setRThetaPhi)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4260( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setREtaPhi)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4261( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setRhoPhiZ)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4262( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setRhoPhiTheta)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4263( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setRhoPhiEta)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static  void method_4264( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getX)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getX)();
}

static  void method_4265( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getY)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getY)();
}

static  void method_4266( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getZ)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getZ)();
}

static  void method_4267( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getR)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getR)();
}

static  void method_4268( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getTheta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getTheta)();
}

static  void method_4269( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getPhi)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getPhi)();
}

static  void method_4270( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->r)());
  else   (((const ::CLHEP::Hep3Vector*)o)->r)();
}

static  void method_4271( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->rho)());
  else   (((const ::CLHEP::Hep3Vector*)o)->rho)();
}

static  void method_4272( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getRho)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getRho)();
}

static  void method_4273( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->eta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->eta)();
}

static  void method_4274( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->getEta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->getEta)();
}

static  void method_4275( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setR)(*(double*)arg[0]);
}

static  void method_4276( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::CLHEP::Hep3Vector*)o)->setRho)(*(double*)arg[0]);
}

static  void method_4277( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::CLHEP::Hep3Vector*)o)->compare)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->compare)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4278( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator>)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator>)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4279( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator<)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator<)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4280( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator>=)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator>=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void operator_4281( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->operator<=)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->operator<=)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4282( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->diff2)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->diff2)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4283( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((::CLHEP::Hep3Vector*)o)->setTolerance)(*(double*)arg[0]));
  else   (((::CLHEP::Hep3Vector*)o)->setTolerance)(*(double*)arg[0]);
}

static  void method_4284( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((::CLHEP::Hep3Vector*)o)->getTolerance)());
  else   (((::CLHEP::Hep3Vector*)o)->getTolerance)();
}

static  void method_4285( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isParallel)(*(const ::CLHEP::Hep3Vector*)arg[0]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isParallel)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isParallel)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isParallel)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]);
  }
}

static  void method_4286( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (bool)((((const ::CLHEP::Hep3Vector*)o)->isOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]));
    else     (((const ::CLHEP::Hep3Vector*)o)->isOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0],
      *(double*)arg[1]);
  }
}

static  void method_4287( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->howParallel)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->howParallel)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4288( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->howOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->howOrthogonal)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4289( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->beta)());
  else   (((const ::CLHEP::Hep3Vector*)o)->beta)();
}

static  void method_4290( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->gamma)());
  else   (((const ::CLHEP::Hep3Vector*)o)->gamma)();
}

static  void method_4291( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->coLinearRapidity)());
  else   (((const ::CLHEP::Hep3Vector*)o)->coLinearRapidity)();
}

static  void method_4292( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->angle)());
  else   (((const ::CLHEP::Hep3Vector*)o)->angle)();
}

static  void method_4293( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->theta)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->theta)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4294( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->cosTheta)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->cosTheta)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4295( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->cos2Theta)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->cos2Theta)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4296( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->project)());
  else   (((const ::CLHEP::Hep3Vector*)o)->project)();
}

static  void method_4297( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->project)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->project)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4298( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->perpPart)());
  else   (((const ::CLHEP::Hep3Vector*)o)->perpPart)();
}

static  void method_4299( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (CLHEP::Hep3Vector)((((const ::CLHEP::Hep3Vector*)o)->perpPart)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->perpPart)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4300( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->rapidity)());
  else   (((const ::CLHEP::Hep3Vector*)o)->rapidity)();
}

static  void method_4301( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->rapidity)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->rapidity)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4302( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->eta)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->eta)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4303( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->polarAngle)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->polarAngle)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4304( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->deltaPhi)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->deltaPhi)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4305( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->azimAngle)(*(const ::CLHEP::Hep3Vector*)arg[0]));
  else   (((const ::CLHEP::Hep3Vector*)o)->azimAngle)(*(const ::CLHEP::Hep3Vector*)arg[0]);
}

static  void method_4306( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->polarAngle)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]));
  else   (((const ::CLHEP::Hep3Vector*)o)->polarAngle)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]);
}

static  void method_4307( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (double)((((const ::CLHEP::Hep3Vector*)o)->azimAngle)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]));
  else   (((const ::CLHEP::Hep3Vector*)o)->azimAngle)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(const ::CLHEP::Hep3Vector*)arg[1]);
}

static  void method_4308( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(double*)arg[1]);
  else   (((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::Hep3Vector*)arg[0],
    *(double*)arg[1]);
}

static  void method_4309( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::HepAxisAngle*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::HepAxisAngle*)arg[0]);
}

static  void method_4310( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::HepEulerAngles*)arg[0]);
  else   (((::CLHEP::Hep3Vector*)o)->rotate)(*(const ::CLHEP::HepEulerAngles*)arg[0]);
}

static  void method_4311( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::CLHEP::Hep3Vector*)o)->rotate)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
  else   (((::CLHEP::Hep3Vector*)o)->rotate)(*(double*)arg[0],
    *(double*)arg[1],
    *(double*)arg[2]);
}

static void method_newdel_1335( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::CLHEP::Hep3Vector >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::CLHEP::Hep3Vector >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::CLHEP::Hep3Vector >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::CLHEP::Hep3Vector >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::CLHEP::Hep3Vector >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

//------Dictionary for class Hep3Vector -------------------------------
void __CLHEP__Hep3Vector_db_datamem(Reflex::Class*);
void __CLHEP__Hep3Vector_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __CLHEP__Hep3Vector_datamem_bld(&__CLHEP__Hep3Vector_db_datamem);
Reflex::GenreflexMemberBuilder __CLHEP__Hep3Vector_funcmem_bld(&__CLHEP__Hep3Vector_db_funcmem);
void __CLHEP__Hep3Vector_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("CLHEP::Hep3Vector"), typeid(::CLHEP::Hep3Vector), sizeof(::CLHEP::Hep3Vector), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL, ::Reflex::CLASS)
  .AddEnum(Reflex::Literal("_87"), Reflex::Literal("X=0;Y=1;Z=2;NUM_COORDINATES=3;SIZE=3"), &typeid(::Reflex::UnnamedEnum), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddEnum(Reflex::Literal("_88"), Reflex::Literal("ToleranceTicks=100"), &typeid(::Reflex::UnnamedEnum), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("Hep3Vector"), constructor_4201, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_355), Reflex::Literal("Hep3Vector"), constructor_4202, 0, "x1", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_355, type_355), Reflex::Literal("Hep3Vector"), constructor_4203, 0, "x1;y1", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_355, type_355, type_355), Reflex::Literal("Hep3Vector"), constructor_4204, 0, "x1;y1;z1", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_9976), Reflex::Literal("Hep3Vector"), constructor_4205, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~Hep3Vector"), destructor_4206, 0, 0, ::Reflex::PUBLIC | ::Reflex::DESTRUCTOR )
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_1335, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandDataMemberBuilder(&__CLHEP__Hep3Vector_datamem_bld)
  .AddOnDemandFunctionMemberBuilder(&__CLHEP__Hep3Vector_funcmem_bld);
}

//------Delayed data member builder for class Hep3Vector -------------------
void __CLHEP__Hep3Vector_db_datamem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddDataMember(type_355, Reflex::Literal("dx"), OffsetOf(__shadow__::__CLHEP__Hep3Vector, dx), ::Reflex::PROTECTED)
  .AddDataMember(type_355, Reflex::Literal("dy"), OffsetOf(__shadow__::__CLHEP__Hep3Vector, dy), ::Reflex::PROTECTED)
  .AddDataMember(type_355, Reflex::Literal("dz"), OffsetOf(__shadow__::__CLHEP__Hep3Vector, dz), ::Reflex::PROTECTED);
}
//------Delayed function member builder for class Hep3Vector -------------------
void __CLHEP__Hep3Vector_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_43), Reflex::Literal("operator()"), operator_4207, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_43), Reflex::Literal("operator[]"), operator_4208, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6756, type_43), Reflex::Literal("operator()"), operator_4209, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6756, type_43), Reflex::Literal("operator[]"), operator_4210, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("x"), method_4211, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("y"), method_4212, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("z"), method_4213, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setX"), method_4214, 0, "x1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setY"), method_4215, 0, "y1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setZ"), method_4216, 0, "z1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("set"), method_4217, 0, "x1;y1;z1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("phi"), method_4218, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("theta"), method_4219, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("cosTheta"), method_4220, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("cos2Theta"), method_4221, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("mag2"), method_4222, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("mag"), method_4223, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setPhi"), method_4224, 0, "ph", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setTheta"), method_4225, 0, "th", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setMag"), method_4226, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("perp2"), method_4227, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("perp"), method_4228, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setPerp"), method_4229, 0, "r1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setCylTheta"), method_4230, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("perp2"), method_4231, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("perp"), method_4232, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_9976), Reflex::Literal("operator="), operator_4233, 0, "p", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator=="), operator_4234, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator!="), operator_4235, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976, type_355), Reflex::Literal("isNear"), method_4236, 0, ";epsilon=CLHEP::Hep3Vector::tolerance", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("howNear"), method_4237, 0, "v", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("deltaR"), method_4238, 0, "v", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_9976), Reflex::Literal("operator+="), operator_4239, 0, "p", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_9976), Reflex::Literal("operator-="), operator_4240, 0, "p", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335), Reflex::Literal("operator-"), operator_4241, 0, 0, ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355), Reflex::Literal("operator*="), operator_4242, 0, "a", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355), Reflex::Literal("operator/="), operator_4243, 0, "", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335), Reflex::Literal("unit"), method_4244, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335), Reflex::Literal("orthogonal"), method_4245, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("dot"), method_4246, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335, type_9976), Reflex::Literal("cross"), method_4247, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("angle"), method_4248, 0, "q", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("pseudoRapidity"), method_4249, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setEta"), method_4250, 0, "p", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setCylEta"), method_4251, 0, "p", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355), Reflex::Literal("rotateX"), method_4252, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355), Reflex::Literal("rotateY"), method_4253, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355), Reflex::Literal("rotateZ"), method_4254, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_9976), Reflex::Literal("rotateUz"), method_4255, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355, type_9976), Reflex::Literal("rotate"), method_4256, 0, ";", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_10284), Reflex::Literal("operator*="), operator_4257, 0, "", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_10284), Reflex::Literal("transform"), method_4258, 0, "", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("setRThetaPhi"), method_4259, 0, "r1;theta1;phi1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("setREtaPhi"), method_4260, 0, "r1;eta1;phi1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("setRhoPhiZ"), method_4261, 0, "rho1;phi1;z1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("setRhoPhiTheta"), method_4262, 0, "rho;phi;theta", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355, type_355, type_355), Reflex::Literal("setRhoPhiEta"), method_4263, 0, "rho;phi;eta", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getX"), method_4264, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getY"), method_4265, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getZ"), method_4266, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getR"), method_4267, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getTheta"), method_4268, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getPhi"), method_4269, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("r"), method_4270, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("rho"), method_4271, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getRho"), method_4272, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("eta"), method_4273, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getEta"), method_4274, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setR"), method_4275, 0, "r1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_355), Reflex::Literal("setRho"), method_4276, 0, "rho1", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_9976), Reflex::Literal("compare"), method_4277, 0, "v", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator>"), operator_4278, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator<"), operator_4279, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator>="), operator_4280, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976), Reflex::Literal("operator<="), operator_4281, 0, "v", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("diff2"), method_4282, 0, "p", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_355), Reflex::Literal("setTolerance"), method_4283, 0, "tol", ::Reflex::PUBLIC | ::Reflex::STATIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("getTolerance"), method_4284, 0, 0, ::Reflex::PUBLIC | ::Reflex::STATIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976, type_355), Reflex::Literal("isParallel"), method_4285, 0, "v;epsilon=CLHEP::Hep3Vector::tolerance", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898, type_9976, type_355), Reflex::Literal("isOrthogonal"), method_4286, 0, "v;epsilon=CLHEP::Hep3Vector::tolerance", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("howParallel"), method_4287, 0, "v", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("howOrthogonal"), method_4288, 0, "v", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("beta"), method_4289, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("gamma"), method_4290, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("coLinearRapidity"), method_4291, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("angle"), method_4292, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("theta"), method_4293, 0, "q", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("cosTheta"), method_4294, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("cos2Theta"), method_4295, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335), Reflex::Literal("project"), method_4296, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335, type_9976), Reflex::Literal("project"), method_4297, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335), Reflex::Literal("perpPart"), method_4298, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1335, type_9976), Reflex::Literal("perpPart"), method_4299, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355), Reflex::Literal("rapidity"), method_4300, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("rapidity"), method_4301, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("eta"), method_4302, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("polarAngle"), method_4303, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("deltaPhi"), method_4304, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976), Reflex::Literal("azimAngle"), method_4305, 0, "v2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976, type_9976), Reflex::Literal("polarAngle"), method_4306, 0, "v2;ref", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_355, type_9976, type_9976), Reflex::Literal("azimAngle"), method_4307, 0, "v2;ref", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_9976, type_355), Reflex::Literal("rotate"), method_4308, 0, "axis;delta", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_10285), Reflex::Literal("rotate"), method_4309, 0, "ax", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_10286), Reflex::Literal("rotate"), method_4310, 0, "e", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10283, type_355, type_355, type_355), Reflex::Literal("rotate"), method_4311, 0, "phi;theta;psi", ::Reflex::PUBLIC);
}
//------Stub functions for class OpNovicePMTHit -------------------------------
static void constructor_4588( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::OpNovicePMTHit();
  else ::new(mem) ::OpNovicePMTHit();
}

static void destructor_4589(void*, void * o, const std::vector<void*>&, void *) {
(((::OpNovicePMTHit*)o)->::OpNovicePMTHit::~OpNovicePMTHit)();
}
static void constructor_4590( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::OpNovicePMTHit(*(const ::OpNovicePMTHit*)arg[0]);
  else ::new(mem) ::OpNovicePMTHit(*(const ::OpNovicePMTHit*)arg[0]);
}

static  void operator_4591( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::OpNovicePMTHit*)o)->operator=)(*(const ::OpNovicePMTHit*)arg[0]);
  else   (((::OpNovicePMTHit*)o)->operator=)(*(const ::OpNovicePMTHit*)arg[0]);
}

static  void operator_4592( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::OpNovicePMTHit*)o)->operator==)(*(const ::OpNovicePMTHit*)arg[0]));
  else   (((const ::OpNovicePMTHit*)o)->operator==)(*(const ::OpNovicePMTHit*)arg[0]);
}

static  void operator_4593( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNovicePMTHit*)o)->operator new)(*(::size_t*)arg[0]));
  else   (((::OpNovicePMTHit*)o)->operator new)(*(::size_t*)arg[0]);
}

static  void operator_4594( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->operator delete)((void*)arg[0]);
}

static  void method_4595( void*, void* o, const std::vector<void*>&, void*)
{
  (((::OpNovicePMTHit*)o)->Draw)();
}

static  void method_4596( void*, void* o, const std::vector<void*>&, void*)
{
  (((::OpNovicePMTHit*)o)->Print)();
}

static  void method_4597( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetDrawit)(*(::G4bool*)arg[0]);
}

static  void method_4598( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((::OpNovicePMTHit*)o)->GetDrawit)());
  else   (((::OpNovicePMTHit*)o)->GetDrawit)();
}

static  void method_4599( void*, void* o, const std::vector<void*>&, void*)
{
  (((::OpNovicePMTHit*)o)->IncrementPhotons)();
}

static  void method_4600( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNovicePMTHit*)o)->GetPhotonCount)());
  else   (((::OpNovicePMTHit*)o)->GetPhotonCount)();
}

static  void method_4601( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetPMTNumber)(*(::G4int*)arg[0]);
}

static  void method_4602( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNovicePMTHit*)o)->GetPMTNumber)());
  else   (((::OpNovicePMTHit*)o)->GetPMTNumber)();
}

static  void method_4603( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetNPixels)(*(::G4int*)arg[0]);
}

static  void method_4604( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNovicePMTHit*)o)->GetNPixels)());
  else   (((::OpNovicePMTHit*)o)->GetNPixels)();
}

static  void method_4605( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetHitData)(*(::G4double*)arg[0],
    *(::G4double*)arg[1],
    *(::G4double*)arg[2],
    *(::G4double*)arg[3]);
}

static  void method_4606( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4double)((((::OpNovicePMTHit*)o)->GetX)(*(int*)arg[0]));
  else   (((::OpNovicePMTHit*)o)->GetX)(*(int*)arg[0]);
}

static  void method_4607( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4double)((((::OpNovicePMTHit*)o)->GetY)(*(int*)arg[0]));
  else   (((::OpNovicePMTHit*)o)->GetY)(*(int*)arg[0]);
}

static  void method_4608( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4double)((((::OpNovicePMTHit*)o)->GetT)(*(int*)arg[0]));
  else   (((::OpNovicePMTHit*)o)->GetT)(*(int*)arg[0]);
}

static  void method_4609( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4double)((((::OpNovicePMTHit*)o)->GetE)(*(int*)arg[0]));
  else   (((::OpNovicePMTHit*)o)->GetE)(*(int*)arg[0]);
}

static  void method_4610( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4double)((((::OpNovicePMTHit*)o)->GetFirstHitTime)());
  else   (((::OpNovicePMTHit*)o)->GetFirstHitTime)();
}

static  void method_4611( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetFirstHitTime)(*(::G4double*)arg[0]);
}

static  void method_4612( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetPMTPhysVol)((::G4VPhysicalVolume*)arg[0]);
}

static  void method_4613( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNovicePMTHit*)o)->GetPMTPhysVol)());
  else   (((::OpNovicePMTHit*)o)->GetPMTPhysVol)();
}

static  void method_4614( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetPMTPhysVolMother)((::G4VPhysicalVolume*)arg[0]);
}

static  void method_4615( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::OpNovicePMTHit*)o)->GetPMTPhysVolMother)());
  else   (((::OpNovicePMTHit*)o)->GetPMTPhysVolMother)();
}

static  void method_4616( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetDrawScaleMax)(*(::G4int*)arg[0]);
}

static  void method_4617( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNovicePMTHit*)o)->GetDrawScaleMax)());
  else   (((::OpNovicePMTHit*)o)->GetDrawScaleMax)();
}

static  void method_4618( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetDrawScaleMin)(*(::G4int*)arg[0]);
}

static  void method_4619( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4int)((((::OpNovicePMTHit*)o)->GetDrawScaleMin)());
  else   (((::OpNovicePMTHit*)o)->GetDrawScaleMin)();
}

static  void method_4620( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::OpNovicePMTHit*)o)->SetName)(*(::G4String*)arg[0]);
}

static  void method_4621( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4String)((((::OpNovicePMTHit*)o)->GetName)());
  else   (((::OpNovicePMTHit*)o)->GetName)();
}

static void method_newdel_1537( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::OpNovicePMTHit >::new_np_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::OpNovicePMTHit >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::OpNovicePMTHit >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::OpNovicePMTHit >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::OpNovicePMTHit >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

static void method_x6( void* retaddr, void*, const std::vector<void*>&, void*)
{
  typedef std::vector<std::pair< ::Reflex::Base, int> > Bases_t;
  static Bases_t s_bases;
  if ( !s_bases.size() ) {
    s_bases.push_back(std::make_pair(::Reflex::Base( ::Reflex::TypeBuilder(Reflex::Literal("G4VHit")), ::Reflex::BaseOffset< ::OpNovicePMTHit,::G4VHit >::Get(),::Reflex::PUBLIC), 0));
  }
  if (retaddr) *(Bases_t**)retaddr = &s_bases;
}

//------Dictionary for class OpNovicePMTHit -------------------------------
void __OpNovicePMTHit_db_datamem(Reflex::Class*);
void __OpNovicePMTHit_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __OpNovicePMTHit_datamem_bld(&__OpNovicePMTHit_db_datamem);
Reflex::GenreflexMemberBuilder __OpNovicePMTHit_funcmem_bld(&__OpNovicePMTHit_db_funcmem);
void __OpNovicePMTHit_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("OpNovicePMTHit"), typeid(::OpNovicePMTHit), sizeof(::OpNovicePMTHit), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::VIRTUAL, ::Reflex::CLASS)
  .AddBase(type_1000, ::Reflex::BaseOffset< ::OpNovicePMTHit, ::G4VHit >::Get(), ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("OpNovicePMTHit"), constructor_4588, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~OpNovicePMTHit"), destructor_4589, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL | ::Reflex::DESTRUCTOR )
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_4815), Reflex::Literal("OpNovicePMTHit"), constructor_4590, 0, "right", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_1537, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getBasesTable"), method_x6, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandDataMemberBuilder(&__OpNovicePMTHit_datamem_bld)
  .AddOnDemandFunctionMemberBuilder(&__OpNovicePMTHit_funcmem_bld);
}

//------Delayed data member builder for class OpNovicePMTHit -------------------
void __OpNovicePMTHit_db_datamem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddDataMember(type_211, Reflex::Literal("fPmtNumber"), OffsetOf(__shadow__::__OpNovicePMTHit, fPmtNumber), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fPhotons"), OffsetOf(__shadow__::__OpNovicePMTHit, fPhotons), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fNPixels"), OffsetOf(__shadow__::__OpNovicePMTHit, fNPixels), ::Reflex::PRIVATE)
  .AddDataMember(type_1353, Reflex::Literal("fFirstTime"), OffsetOf(__shadow__::__OpNovicePMTHit, fFirstTime), ::Reflex::PRIVATE)
  .AddDataMember(type_2064, Reflex::Literal("fName"), OffsetOf(__shadow__::__OpNovicePMTHit, fName), ::Reflex::PRIVATE)
  .AddDataMember(type_2248, Reflex::Literal("fTime"), OffsetOf(__shadow__::__OpNovicePMTHit, fTime), ::Reflex::PRIVATE)
  .AddDataMember(type_2248, Reflex::Literal("fEnergy"), OffsetOf(__shadow__::__OpNovicePMTHit, fEnergy), ::Reflex::PRIVATE)
  .AddDataMember(type_2248, Reflex::Literal("fX"), OffsetOf(__shadow__::__OpNovicePMTHit, fX), ::Reflex::PRIVATE)
  .AddDataMember(type_2248, Reflex::Literal("fY"), OffsetOf(__shadow__::__OpNovicePMTHit, fY), ::Reflex::PRIVATE)
  .AddDataMember(type_6509, Reflex::Literal("fPhysVolMother"), OffsetOf(__shadow__::__OpNovicePMTHit, fPhysVolMother), ::Reflex::PRIVATE | ::Reflex::TRANSIENT)
  .AddDataMember(type_6509, Reflex::Literal("fPhysVol"), OffsetOf(__shadow__::__OpNovicePMTHit, fPhysVol), ::Reflex::PRIVATE | ::Reflex::TRANSIENT)
  .AddDataMember(type_1908, Reflex::Literal("fDrawit"), OffsetOf(__shadow__::__OpNovicePMTHit, fDrawit), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fDrawScaleMin"), OffsetOf(__shadow__::__OpNovicePMTHit, fDrawScaleMin), ::Reflex::PRIVATE)
  .AddDataMember(type_211, Reflex::Literal("fDrawScaleMax"), OffsetOf(__shadow__::__OpNovicePMTHit, fDrawScaleMax), ::Reflex::PRIVATE);
}
//------Delayed function member builder for class OpNovicePMTHit -------------------
void __OpNovicePMTHit_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_4815, type_4815), Reflex::Literal("operator="), operator_4591, 0, "right", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_4815), Reflex::Literal("operator=="), operator_4592, 0, "right", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_240, type_1343), Reflex::Literal("operator new"), operator_4593, 0, "", ::Reflex::PUBLIC | ::Reflex::STATIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_240), Reflex::Literal("operator delete"), operator_4594, 0, "aHit", ::Reflex::PUBLIC | ::Reflex::STATIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Draw"), method_4595, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("Print"), method_4596, 0, 0, ::Reflex::PUBLIC | ::Reflex::VIRTUAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1908), Reflex::Literal("SetDrawit"), method_4597, 0, "b", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908), Reflex::Literal("GetDrawit"), method_4598, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("IncrementPhotons"), method_4599, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetPhotonCount"), method_4600, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetPMTNumber"), method_4601, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetPMTNumber"), method_4602, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetNPixels"), method_4603, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetNPixels"), method_4604, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1353, type_1353, type_1353, type_1353), Reflex::Literal("SetHitData"), method_4605, 0, "t;e;x;y", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1353, type_43), Reflex::Literal("GetX"), method_4606, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1353, type_43), Reflex::Literal("GetY"), method_4607, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1353, type_43), Reflex::Literal("GetT"), method_4608, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1353, type_43), Reflex::Literal("GetE"), method_4609, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1353), Reflex::Literal("GetFirstHitTime"), method_4610, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1353), Reflex::Literal("SetFirstHitTime"), method_4611, 0, "t", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6509), Reflex::Literal("SetPMTPhysVol"), method_4612, 0, "physVol", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6509), Reflex::Literal("GetPMTPhysVol"), method_4613, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6509), Reflex::Literal("SetPMTPhysVolMother"), method_4614, 0, "physVol", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6509), Reflex::Literal("GetPMTPhysVolMother"), method_4615, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetDrawScaleMax"), method_4616, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetDrawScaleMax"), method_4617, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_211), Reflex::Literal("SetDrawScaleMin"), method_4618, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211), Reflex::Literal("GetDrawScaleMin"), method_4619, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_2064), Reflex::Literal("SetName"), method_4620, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2064), Reflex::Literal("GetName"), method_4621, 0, 0, ::Reflex::PUBLIC);
}
//------Stub functions for class G4String -------------------------------
static void constructor_5150( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String();
  else ::new(mem) ::G4String();
}

static void constructor_5151( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String(*(char*)arg[0]);
  else ::new(mem) ::G4String(*(char*)arg[0]);
}

static void constructor_5152( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String((const char*)arg[0]);
  else ::new(mem) ::G4String((const char*)arg[0]);
}

static void constructor_5153( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String((const char*)arg[0],
      *(::str_size*)arg[1]);
  else ::new(mem) ::G4String((const char*)arg[0],
      *(::str_size*)arg[1]);
}

static void constructor_5154( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String(*(const ::G4String*)arg[0]);
  else ::new(mem) ::G4String(*(const ::G4String*)arg[0]);
}

static void constructor_5155( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String(*(const ::G4SubString*)arg[0]);
  else ::new(mem) ::G4String(*(const ::G4SubString*)arg[0]);
}

static void constructor_5156( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::G4String(*(const ::std::string*)arg[0]);
  else ::new(mem) ::G4String(*(const ::std::string*)arg[0]);
}

static void destructor_5157(void*, void * o, const std::vector<void*>&, void *) {
(((::G4String*)o)->::G4String::~G4String)();
}
static  void operator_5158( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator=)(*(const ::G4String*)arg[0]);
  else   (((::G4String*)o)->operator=)(*(const ::G4String*)arg[0]);
}

static  void operator_5159( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator=)(*(const ::std::string*)arg[0]);
  else   (((::G4String*)o)->operator=)(*(const ::std::string*)arg[0]);
}

static  void operator_5160( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator=)((const char*)arg[0]);
  else   (((::G4String*)o)->operator=)((const char*)arg[0]);
}

static  void operator_5161( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (char)((((const ::G4String*)o)->operator())(*(::str_size*)arg[0]));
  else   (((const ::G4String*)o)->operator())(*(::str_size*)arg[0]);
}

static  void operator_5162( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator())(*(::str_size*)arg[0]);
  else   (((::G4String*)o)->operator())(*(::str_size*)arg[0]);
}

static  void operator_5163( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator+=)(*(const ::G4SubString*)arg[0]);
  else   (((::G4String*)o)->operator+=)(*(const ::G4SubString*)arg[0]);
}

static  void operator_5164( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator+=)((const char*)arg[0]);
  else   (((::G4String*)o)->operator+=)((const char*)arg[0]);
}

static  void operator_5165( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator+=)(*(const ::std::string*)arg[0]);
  else   (((::G4String*)o)->operator+=)(*(const ::std::string*)arg[0]);
}

static  void operator_5166( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->operator+=)(*(const char*)arg[0]);
  else   (((::G4String*)o)->operator+=)(*(const char*)arg[0]);
}

static  void operator_5167( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->operator==)(*(const ::G4String*)arg[0]));
  else   (((const ::G4String*)o)->operator==)(*(const ::G4String*)arg[0]);
}

static  void operator_5168( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->operator==)((const char*)arg[0]));
  else   (((const ::G4String*)o)->operator==)((const char*)arg[0]);
}

static  void operator_5169( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->operator!=)(*(const ::G4String*)arg[0]));
  else   (((const ::G4String*)o)->operator!=)(*(const ::G4String*)arg[0]);
}

static  void operator_5170( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->operator!=)((const char*)arg[0]));
  else   (((const ::G4String*)o)->operator!=)((const char*)arg[0]);
}

static  void converter_5171( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4String*)o)->operator const char*)());
  else   (((const ::G4String*)o)->operator const char*)();
}

static  void operator_5172( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4SubString)((((::G4String*)o)->operator())(*(::str_size*)arg[0],
    *(::str_size*)arg[1]));
  else   (((::G4String*)o)->operator())(*(::str_size*)arg[0],
    *(::str_size*)arg[1]);
}

static  void method_5173( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->compareTo)((const char*)arg[0]));
    else     (((const ::G4String*)o)->compareTo)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->compareTo)((const char*)arg[0],
      *(::G4String::caseCompare*)arg[1]));
    else     (((const ::G4String*)o)->compareTo)((const char*)arg[0],
      *(::G4String::caseCompare*)arg[1]);
  }
}

static  void method_5174( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->compareTo)(*(const ::G4String*)arg[0]));
    else     (((const ::G4String*)o)->compareTo)(*(const ::G4String*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->compareTo)(*(const ::G4String*)arg[0],
      *(::G4String::caseCompare*)arg[1]));
    else     (((const ::G4String*)o)->compareTo)(*(const ::G4String*)arg[0],
      *(::G4String::caseCompare*)arg[1]);
  }
}

static  void method_5175( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->prepend)((const char*)arg[0]);
  else   (((::G4String*)o)->prepend)((const char*)arg[0]);
}

static  void method_5176( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->append)(*(const ::G4String*)arg[0]);
  else   (((::G4String*)o)->append)(*(const ::G4String*)arg[0]);
}

static  void method_5177( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->readLine)(*(::std::istream*)arg[0]);
    else     (((::G4String*)o)->readLine)(*(::std::istream*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->readLine)(*(::std::istream*)arg[0],
      *(::G4bool*)arg[1]);
    else     (((::G4String*)o)->readLine)(*(::std::istream*)arg[0],
      *(::G4bool*)arg[1]);
  }
}

static  void method_5178( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->replace)(*(unsigned int*)arg[0],
    *(unsigned int*)arg[1],
    (const char*)arg[2],
    *(unsigned int*)arg[3]);
  else   (((::G4String*)o)->replace)(*(unsigned int*)arg[0],
    *(unsigned int*)arg[1],
    (const char*)arg[2],
    *(unsigned int*)arg[3]);
}

static  void method_5179( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->replace)(*(::str_size*)arg[0],
    *(::str_size*)arg[1],
    (const char*)arg[2]);
  else   (((::G4String*)o)->replace)(*(::str_size*)arg[0],
    *(::str_size*)arg[1],
    (const char*)arg[2]);
}

static  void method_5180( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->remove)(*(::str_size*)arg[0]);
  else   (((::G4String*)o)->remove)(*(::str_size*)arg[0]);
}

static  void method_5181( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::G4String*)o)->remove)(*(::str_size*)arg[0],
    *(::str_size*)arg[1]);
  else   (((::G4String*)o)->remove)(*(::str_size*)arg[0],
    *(::str_size*)arg[1]);
}

static  void method_5182( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->first)(*(char*)arg[0]));
  else   (((const ::G4String*)o)->first)(*(char*)arg[0]);
}

static  void method_5183( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->last)(*(char*)arg[0]));
  else   (((const ::G4String*)o)->last)(*(char*)arg[0]);
}

static  void method_5184( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->contains)(*(const ::std::string*)arg[0]));
  else   (((const ::G4String*)o)->contains)(*(const ::std::string*)arg[0]);
}

static  void method_5185( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->contains)(*(char*)arg[0]));
  else   (((const ::G4String*)o)->contains)(*(char*)arg[0]);
}

static  void method_5186( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 0 ) {
    if (retaddr) new (retaddr) (G4String)((((::G4String*)o)->strip)());
    else     (((::G4String*)o)->strip)();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) new (retaddr) (G4String)((((::G4String*)o)->strip)(*(::G4int*)arg[0]));
    else     (((::G4String*)o)->strip)(*(::G4int*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (G4String)((((::G4String*)o)->strip)(*(::G4int*)arg[0],
      *(char*)arg[1]));
    else     (((::G4String*)o)->strip)(*(::G4int*)arg[0],
      *(char*)arg[1]);
  }
}

static  void method_5187( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4String*)o)->toLower)();
}

static  void method_5188( void*, void* o, const std::vector<void*>&, void*)
{
  (((::G4String*)o)->toUpper)();
}

static  void method_5189( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (G4bool)((((const ::G4String*)o)->isNull)());
  else   (((const ::G4String*)o)->isNull)();
}

static  void method_5190( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (str_size)((((const ::G4String*)o)->index)((const char*)arg[0]));
    else     (((const ::G4String*)o)->index)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (str_size)((((const ::G4String*)o)->index)((const char*)arg[0],
      *(::G4int*)arg[1]));
    else     (((const ::G4String*)o)->index)((const char*)arg[0],
      *(::G4int*)arg[1]);
  }
}

static  void method_5191( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (str_size)((((const ::G4String*)o)->index)(*(char*)arg[0]));
    else     (((const ::G4String*)o)->index)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (str_size)((((const ::G4String*)o)->index)(*(char*)arg[0],
      *(::G4int*)arg[1]));
    else     (((const ::G4String*)o)->index)(*(char*)arg[0],
      *(::G4int*)arg[1]);
  }
}

static  void method_5192( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (str_size)((((const ::G4String*)o)->index)(*(const ::G4String*)arg[0],
    *(::str_size*)arg[1],
    *(::str_size*)arg[2],
    *(::G4String::caseCompare*)arg[3]));
  else   (((const ::G4String*)o)->index)(*(const ::G4String*)arg[0],
    *(::str_size*)arg[1],
    *(::str_size*)arg[2],
    *(::G4String::caseCompare*)arg[3]);
}

static  void method_5193( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::G4String*)o)->data)());
  else   (((const ::G4String*)o)->data)();
}

static  void method_5194( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (G4int)((((const ::G4String*)o)->strcasecompare)((const char*)arg[0],
    (const char*)arg[1]));
  else   (((const ::G4String*)o)->strcasecompare)((const char*)arg[0],
    (const char*)arg[1]);
}

static  void method_5195( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 0 ) {
    if (retaddr) new (retaddr) (unsigned int)((((const ::G4String*)o)->hash)());
    else     (((const ::G4String*)o)->hash)();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) new (retaddr) (unsigned int)((((const ::G4String*)o)->hash)(*(::G4String::caseCompare*)arg[0]));
    else     (((const ::G4String*)o)->hash)(*(::G4String::caseCompare*)arg[0]);
  }
}

static  void method_5196( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (unsigned int)((((const ::G4String*)o)->stlhash)());
  else   (((const ::G4String*)o)->stlhash)();
}

static void method_newdel_2064( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::G4String >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::G4String >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::G4String >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::G4String >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::G4String >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

static void method_x8( void* retaddr, void*, const std::vector<void*>&, void*)
{
  typedef std::vector<std::pair< ::Reflex::Base, int> > Bases_t;
  static Bases_t s_bases;
  if ( !s_bases.size() ) {
    s_bases.push_back(std::make_pair(::Reflex::Base( ::Reflex::TypeBuilder(Reflex::Literal("std::basic_string<char>")), ::Reflex::BaseOffset< ::G4String,::std::basic_string<char> >::Get(),::Reflex::PUBLIC), 0));
  }
  if (retaddr) *(Bases_t**)retaddr = &s_bases;
}

//------Dictionary for class G4String -------------------------------
void __G4String_db_datamem(Reflex::Class*);
void __G4String_db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __G4String_datamem_bld(&__G4String_db_datamem);
Reflex::GenreflexMemberBuilder __G4String_funcmem_bld(&__G4String_db_funcmem);
void __G4String_dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("G4String"), typeid(::G4String), sizeof(::G4String), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL, ::Reflex::CLASS)
  .AddBase(type_2265, ::Reflex::BaseOffset< ::G4String, ::std::basic_string<char> >::Get(), ::Reflex::PUBLIC)
  .AddTypedef(type_2279, Reflex::Literal("G4String::std_string"))
  .AddEnum(Reflex::Literal("G4String::caseCompare"), Reflex::Literal("exact=0;ignoreCase=1"), &typeid(G4String::caseCompare), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddEnum(Reflex::Literal("G4String::stripType"), Reflex::Literal("leading=0;trailing=1;both=2"), &typeid(G4String::stripType), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("G4String"), constructor_5150, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_302), Reflex::Literal("G4String"), constructor_5151, 0, "ch", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_2727), Reflex::Literal("G4String"), constructor_5152, 0, "astring", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_2727, type_451), Reflex::Literal("G4String"), constructor_5153, 0, "astring;len", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_9784), Reflex::Literal("G4String"), constructor_5154, 0, "str", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_10872), Reflex::Literal("G4String"), constructor_5155, 0, "str", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_8626), Reflex::Literal("G4String"), constructor_5156, 0, "str", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~G4String"), destructor_5157, 0, 0, ::Reflex::PUBLIC | ::Reflex::DESTRUCTOR )
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_2064, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getBasesTable"), method_x8, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandFunctionMemberBuilder(&__G4String_funcmem_bld);
}

//------Delayed data member builder for class G4String -------------------
void __G4String_db_datamem(Reflex::Class*) {

}
//------Delayed function member builder for class G4String -------------------
void __G4String_db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_9784), Reflex::Literal("operator="), operator_5158, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_8626), Reflex::Literal("operator="), operator_5159, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_2727), Reflex::Literal("operator="), operator_5160, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_302, type_451), Reflex::Literal("operator()"), operator_5161, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6588, type_451), Reflex::Literal("operator()"), operator_5162, 0, "i", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_10872), Reflex::Literal("operator+="), operator_5163, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_2727), Reflex::Literal("operator+="), operator_5164, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_8626), Reflex::Literal("operator+="), operator_5165, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_7154), Reflex::Literal("operator+="), operator_5166, 0, "ch", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_9784), Reflex::Literal("operator=="), operator_5167, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_2727), Reflex::Literal("operator=="), operator_5168, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_9784), Reflex::Literal("operator!="), operator_5169, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_2727), Reflex::Literal("operator!="), operator_5170, 0, "str", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2727), Reflex::Literal("operator const char*"), converter_5171, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONVERTER | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1621, type_451, type_451), Reflex::Literal("operator()"), operator_5172, 0, "start;extent", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_2727, type_5148), Reflex::Literal("compareTo"), method_5173, 0, "str;mode=exact", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_9784, type_5148), Reflex::Literal("compareTo"), method_5174, 0, "str;mode=exact", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_2727), Reflex::Literal("prepend"), method_5175, 0, "str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_9784), Reflex::Literal("append"), method_5176, 0, "str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10176, type_10176, type_1908), Reflex::Literal("readLine"), method_5177, 0, "strm;skipWhite=true", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_199, type_199, type_2727, type_199), Reflex::Literal("replace"), method_5178, 0, "start;nbytes;buff;n2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_451, type_451, type_2727), Reflex::Literal("replace"), method_5179, 0, "pos;n;str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_451), Reflex::Literal("remove"), method_5180, 0, "n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_10874, type_451, type_451), Reflex::Literal("remove"), method_5181, 0, "pos;N", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_302), Reflex::Literal("first"), method_5182, 0, "ch", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_302), Reflex::Literal("last"), method_5183, 0, "ch", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_8626), Reflex::Literal("contains"), method_5184, 0, "str", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908, type_302), Reflex::Literal("contains"), method_5185, 0, "ch", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2064, type_211, type_302), Reflex::Literal("strip"), method_5186, 0, "strip_Type=trailing;ch=' '", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("toLower"), method_5187, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("toUpper"), method_5188, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1908), Reflex::Literal("isNull"), method_5189, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_451, type_2727, type_211), Reflex::Literal("index"), method_5190, 0, "str;pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_451, type_302, type_211), Reflex::Literal("index"), method_5191, 0, "ch;pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_451, type_9784, type_451, type_451, type_5148), Reflex::Literal("index"), method_5192, 0, "str;ln;st;", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2727), Reflex::Literal("data"), method_5193, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_211, type_2727, type_2727), Reflex::Literal("strcasecompare"), method_5194, 0, "s1;s2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_199, type_5148), Reflex::Literal("hash"), method_5195, 0, "", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_199), Reflex::Literal("stlhash"), method_5196, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST);
}
//------Stub functions for class vector<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > -------------------------------
static void constructor_6646( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 0 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>();
  else ::new(mem) ::std::vector<OpNoviceDigi*>();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>(*(const ::std::allocator<OpNoviceDigi*>*)arg[0]);
  else ::new(mem) ::std::vector<OpNoviceDigi*>(*(const ::std::allocator<OpNoviceDigi*>*)arg[0]);
  }
}

static void constructor_6647( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 1 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0]);
  else ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0],
      *(::OpNoviceDigi* const*)arg[1]);
  else ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0],
      *(::OpNoviceDigi* const*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0],
      *(::OpNoviceDigi* const*)arg[1],
      *(const ::std::allocator<OpNoviceDigi*>*)arg[2]);
  else ::new(mem) ::std::vector<OpNoviceDigi*>(*(::size_t*)arg[0],
      *(::OpNoviceDigi* const*)arg[1],
      *(const ::std::allocator<OpNoviceDigi*>*)arg[2]);
  }
}

static void constructor_6648( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>(*(const ::std::vector<OpNoviceDigi*>*)arg[0]);
  else ::new(mem) ::std::vector<OpNoviceDigi*>(*(const ::std::vector<OpNoviceDigi*>*)arg[0]);
}

static void destructor_6649(void*, void * o, const std::vector<void*>&, void *) {
(((::std::vector<OpNoviceDigi*>*)o)->::std::vector<OpNoviceDigi*>::~vector)();
}
static  void operator_6650( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNoviceDigi*>*)o)->operator=)(*(const ::std::vector<OpNoviceDigi*>*)arg[0]);
  else   (((::std::vector<OpNoviceDigi*>*)o)->operator=)(*(const ::std::vector<OpNoviceDigi*>*)arg[0]);
}

static  void method_6651( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->assign)(*(::size_t*)arg[0],
    *(::OpNoviceDigi* const*)arg[1]);
}

static  void method_6652( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >)((((::std::vector<OpNoviceDigi*>*)o)->begin)());
  else   (((::std::vector<OpNoviceDigi*>*)o)->begin)();
}

static  void method_6653( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi* const*,std::vector<OpNoviceDigi*> >)((((const ::std::vector<OpNoviceDigi*>*)o)->begin)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->begin)();
}

static  void method_6654( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >)((((::std::vector<OpNoviceDigi*>*)o)->end)());
  else   (((::std::vector<OpNoviceDigi*>*)o)->end)();
}

static  void method_6655( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi* const*,std::vector<OpNoviceDigi*> >)((((const ::std::vector<OpNoviceDigi*>*)o)->end)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->end)();
}

static  void method_6660( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNoviceDigi*>*)o)->size)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->size)();
}

static  void method_6661( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNoviceDigi*>*)o)->max_size)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->max_size)();
}

static  void method_6662( void*, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    (((::std::vector<OpNoviceDigi*>*)o)->resize)(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    (((::std::vector<OpNoviceDigi*>*)o)->resize)(*(::size_t*)arg[0],
      (::OpNoviceDigi*)arg[1]);
  }
}

static  void method_6663( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNoviceDigi*>*)o)->capacity)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->capacity)();
}

static  void method_6664( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::std::vector<OpNoviceDigi*>*)o)->empty)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->empty)();
}

static  void method_6665( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->reserve)(*(::size_t*)arg[0]);
}

static  void operator_6666( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNoviceDigi*>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((::std::vector<OpNoviceDigi*>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void operator_6667( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNoviceDigi*>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void method_6669( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNoviceDigi*>*)o)->at)(*(::size_t*)arg[0]);
  else   (((::std::vector<OpNoviceDigi*>*)o)->at)(*(::size_t*)arg[0]);
}

static  void method_6670( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNoviceDigi*>*)o)->at)(*(::size_t*)arg[0]);
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->at)(*(::size_t*)arg[0]);
}

static  void method_6671( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNoviceDigi*>*)o)->front)();
  else   (((::std::vector<OpNoviceDigi*>*)o)->front)();
}

static  void method_6672( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNoviceDigi*>*)o)->front)();
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->front)();
}

static  void method_6673( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNoviceDigi*>*)o)->back)();
  else   (((::std::vector<OpNoviceDigi*>*)o)->back)();
}

static  void method_6674( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNoviceDigi*>*)o)->back)();
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->back)();
}

static  void method_6675( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::std::vector<OpNoviceDigi*>*)o)->data)());
  else   (((::std::vector<OpNoviceDigi*>*)o)->data)();
}

static  void method_6676( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::std::vector<OpNoviceDigi*>*)o)->data)());
  else   (((const ::std::vector<OpNoviceDigi*>*)o)->data)();
}

static  void method_6677( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->push_back)(*(::OpNoviceDigi* const*)arg[0]);
}

static  void method_6678( void*, void* o, const std::vector<void*>&, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->pop_back)();
}

static  void method_6679( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >)((((::std::vector<OpNoviceDigi*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0],
    *(::OpNoviceDigi* const*)arg[1]));
  else   (((::std::vector<OpNoviceDigi*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0],
    *(::OpNoviceDigi* const*)arg[1]);
}

static  void method_6680( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0],
    *(::size_t*)arg[1],
    *(::OpNoviceDigi* const*)arg[2]);
}

static  void method_6681( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >)((((::std::vector<OpNoviceDigi*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0]));
  else   (((::std::vector<OpNoviceDigi*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0]);
}

static  void method_6682( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >)((((::std::vector<OpNoviceDigi*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[1]));
  else   (((::std::vector<OpNoviceDigi*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<OpNoviceDigi**,std::vector<OpNoviceDigi*> >*)arg[1]);
}

static  void method_6683( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->swap)(*(::std::vector<OpNoviceDigi*>*)arg[0]);
}

static  void method_6684( void*, void* o, const std::vector<void*>&, void*)
{
  (((::std::vector<OpNoviceDigi*>*)o)->clear)();
}

static void constructor_x9( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNoviceDigi*>();
  else ::new(mem) ::std::vector<OpNoviceDigi*>();
}

static void method_newdel_2245( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::std::vector<OpNoviceDigi*> >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::std::vector<OpNoviceDigi*> >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::std::vector<OpNoviceDigi*> >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::std::vector<OpNoviceDigi*> >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::std::vector<OpNoviceDigi*> >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

static void method_x11( void* retaddr, void*, const std::vector<void*>&, void*)
{
  typedef std::vector<std::pair< ::Reflex::Base, int> > Bases_t;
  static Bases_t s_bases;
  if ( !s_bases.size() ) {
    s_bases.push_back(std::make_pair(::Reflex::Base( ::Reflex::TypeBuilder(Reflex::Literal("std::_Vector_base<OpNoviceDigi*,std::allocator<OpNoviceDigi*> >")), ::Reflex::BaseOffset< ::std::vector<OpNoviceDigi*>,::std::_Vector_base<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > >::Get(),::Reflex::PROTECTED), 0));
  }
  if (retaddr) *(Bases_t**)retaddr = &s_bases;
}

static void method_x12( void* retaddr, void*, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**) retaddr = ::Reflex::Proxy< ::std::vector<OpNoviceDigi*> >::Generate();
  else ::Reflex::Proxy< ::std::vector<OpNoviceDigi*> >::Generate();
}

//------Dictionary for class vector<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > -------------------------------
void __std__vector_OpNoviceDigip__db_datamem(Reflex::Class*);
void __std__vector_OpNoviceDigip__db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __std__vector_OpNoviceDigip__datamem_bld(&__std__vector_OpNoviceDigip__db_datamem);
Reflex::GenreflexMemberBuilder __std__vector_OpNoviceDigip__funcmem_bld(&__std__vector_OpNoviceDigip__db_funcmem);
void __std__vector_OpNoviceDigip__dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("std::vector<OpNoviceDigi*>"), typeid(::std::vector<OpNoviceDigi*>), sizeof(::std::vector<OpNoviceDigi*>), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL, ::Reflex::CLASS)
  .AddBase(type_2603, ::Reflex::BaseOffset< ::std::vector<OpNoviceDigi*>, ::std::_Vector_base<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > >::Get(), ::Reflex::PROTECTED)
  .AddTypedef(type_4753, Reflex::Literal("std::vector<OpNoviceDigi*>::_Alloc_value_type"))
  .AddTypedef(type_2603, Reflex::Literal("std::vector<OpNoviceDigi*>::_Base"))
  .AddTypedef(type_2397, Reflex::Literal("std::vector<OpNoviceDigi*>::_Tp_alloc_type"))
  .AddTypedef(type_4753, Reflex::Literal("std::vector<OpNoviceDigi*>::value_type"))
  .AddTypedef(type_6631, Reflex::Literal("std::vector<OpNoviceDigi*>::pointer"))
  .AddTypedef(type_6633, Reflex::Literal("std::vector<OpNoviceDigi*>::const_pointer"))
  .AddTypedef(type_6635, Reflex::Literal("std::vector<OpNoviceDigi*>::reference"))
  .AddTypedef(type_6637, Reflex::Literal("std::vector<OpNoviceDigi*>::const_reference"))
  .AddTypedef(type_3151, Reflex::Literal("std::vector<OpNoviceDigi*>::iterator"))
  .AddTypedef(type_3152, Reflex::Literal("std::vector<OpNoviceDigi*>::const_iterator"))
  .AddTypedef(type_2506, Reflex::Literal("std::vector<OpNoviceDigi*>::const_reverse_iterator"))
  .AddTypedef(type_2507, Reflex::Literal("std::vector<OpNoviceDigi*>::reverse_iterator"))
  .AddTypedef(type_1343, Reflex::Literal("std::vector<OpNoviceDigi*>::size_type"))
  .AddTypedef(type_1043, Reflex::Literal("std::vector<OpNoviceDigi*>::difference_type"))
  .AddTypedef(type_2397, Reflex::Literal("std::vector<OpNoviceDigi*>::allocator_type"))
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_11143), Reflex::Literal("vector"), constructor_6646, 0, "__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_1343, type_6637, type_11143), Reflex::Literal("vector"), constructor_6647, 0, "__n;__value=_Tp();__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_11144), Reflex::Literal("vector"), constructor_6648, 0, "__x", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~vector"), destructor_6649, 0, 0, ::Reflex::PUBLIC | ::Reflex::DESTRUCTOR )
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("vector"), constructor_x9, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_2245, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getBasesTable"), method_x11, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("createCollFuncTable"), method_x12, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandFunctionMemberBuilder(&__std__vector_OpNoviceDigip__funcmem_bld);
}

//------Delayed data member builder for class vector<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > -------------------
void __std__vector_OpNoviceDigip__db_datamem(Reflex::Class*) {

}
//------Delayed function member builder for class vector<OpNoviceDigi*,std::allocator<OpNoviceDigi*> > -------------------
void __std__vector_OpNoviceDigip__db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_11145, type_11144), Reflex::Literal("operator="), operator_6650, 0, "__x", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343, type_6637), Reflex::Literal("assign"), method_6651, 0, "__n;__val", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3151), Reflex::Literal("begin"), method_6652, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3152), Reflex::Literal("begin"), method_6653, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3151), Reflex::Literal("end"), method_6654, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3152), Reflex::Literal("end"), method_6655, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("size"), method_6660, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("max_size"), method_6661, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343, type_4753), Reflex::Literal("resize"), method_6662, 0, "__new_size;__x=_Tp()", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("capacity"), method_6663, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898), Reflex::Literal("empty"), method_6664, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343), Reflex::Literal("reserve"), method_6665, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6635, type_1343), Reflex::Literal("operator[]"), operator_6666, 0, "__n", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6637, type_1343), Reflex::Literal("operator[]"), operator_6667, 0, "__n", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6635, type_1343), Reflex::Literal("at"), method_6669, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6637, type_1343), Reflex::Literal("at"), method_6670, 0, "__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6635), Reflex::Literal("front"), method_6671, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6637), Reflex::Literal("front"), method_6672, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6635), Reflex::Literal("back"), method_6673, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6637), Reflex::Literal("back"), method_6674, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6631), Reflex::Literal("data"), method_6675, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6633), Reflex::Literal("data"), method_6676, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6637), Reflex::Literal("push_back"), method_6677, 0, "__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("pop_back"), method_6678, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3151, type_3151, type_6637), Reflex::Literal("insert"), method_6679, 0, "__position;__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_3151, type_1343, type_6637), Reflex::Literal("insert"), method_6680, 0, "__position;__n;__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3151, type_3151), Reflex::Literal("erase"), method_6681, 0, "__position", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3151, type_3151, type_3151), Reflex::Literal("erase"), method_6682, 0, "__first;__last", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_11145), Reflex::Literal("swap"), method_6683, 0, "__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("clear"), method_6684, 0, 0, ::Reflex::PUBLIC);
}
//------Stub functions for class vector<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > -------------------------------
static void constructor_6707( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 0 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>();
  else ::new(mem) ::std::vector<OpNovicePMTHit*>();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>(*(const ::std::allocator<OpNovicePMTHit*>*)arg[0]);
  else ::new(mem) ::std::vector<OpNovicePMTHit*>(*(const ::std::allocator<OpNovicePMTHit*>*)arg[0]);
  }
}

static void constructor_6708( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 1 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0]);
  else ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0],
      *(::OpNovicePMTHit* const*)arg[1]);
  else ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0],
      *(::OpNovicePMTHit* const*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0],
      *(::OpNovicePMTHit* const*)arg[1],
      *(const ::std::allocator<OpNovicePMTHit*>*)arg[2]);
  else ::new(mem) ::std::vector<OpNovicePMTHit*>(*(::size_t*)arg[0],
      *(::OpNovicePMTHit* const*)arg[1],
      *(const ::std::allocator<OpNovicePMTHit*>*)arg[2]);
  }
}

static void constructor_6709( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>(*(const ::std::vector<OpNovicePMTHit*>*)arg[0]);
  else ::new(mem) ::std::vector<OpNovicePMTHit*>(*(const ::std::vector<OpNovicePMTHit*>*)arg[0]);
}

static void destructor_6710(void*, void * o, const std::vector<void*>&, void *) {
(((::std::vector<OpNovicePMTHit*>*)o)->::std::vector<OpNovicePMTHit*>::~vector)();
}
static  void operator_6711( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNovicePMTHit*>*)o)->operator=)(*(const ::std::vector<OpNovicePMTHit*>*)arg[0]);
  else   (((::std::vector<OpNovicePMTHit*>*)o)->operator=)(*(const ::std::vector<OpNovicePMTHit*>*)arg[0]);
}

static  void method_6712( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->assign)(*(::size_t*)arg[0],
    *(::OpNovicePMTHit* const*)arg[1]);
}

static  void method_6713( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >)((((::std::vector<OpNovicePMTHit*>*)o)->begin)());
  else   (((::std::vector<OpNovicePMTHit*>*)o)->begin)();
}

static  void method_6714( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit* const*,std::vector<OpNovicePMTHit*> >)((((const ::std::vector<OpNovicePMTHit*>*)o)->begin)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->begin)();
}

static  void method_6715( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >)((((::std::vector<OpNovicePMTHit*>*)o)->end)());
  else   (((::std::vector<OpNovicePMTHit*>*)o)->end)();
}

static  void method_6716( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit* const*,std::vector<OpNovicePMTHit*> >)((((const ::std::vector<OpNovicePMTHit*>*)o)->end)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->end)();
}

static  void method_6721( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNovicePMTHit*>*)o)->size)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->size)();
}

static  void method_6722( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNovicePMTHit*>*)o)->max_size)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->max_size)();
}

static  void method_6723( void*, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    (((::std::vector<OpNovicePMTHit*>*)o)->resize)(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    (((::std::vector<OpNovicePMTHit*>*)o)->resize)(*(::size_t*)arg[0],
      (::OpNovicePMTHit*)arg[1]);
  }
}

static  void method_6724( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::vector<OpNovicePMTHit*>*)o)->capacity)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->capacity)();
}

static  void method_6725( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::std::vector<OpNovicePMTHit*>*)o)->empty)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->empty)();
}

static  void method_6726( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->reserve)(*(::size_t*)arg[0]);
}

static  void operator_6727( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNovicePMTHit*>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((::std::vector<OpNovicePMTHit*>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void operator_6728( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNovicePMTHit*>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void method_6730( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNovicePMTHit*>*)o)->at)(*(::size_t*)arg[0]);
  else   (((::std::vector<OpNovicePMTHit*>*)o)->at)(*(::size_t*)arg[0]);
}

static  void method_6731( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNovicePMTHit*>*)o)->at)(*(::size_t*)arg[0]);
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->at)(*(::size_t*)arg[0]);
}

static  void method_6732( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNovicePMTHit*>*)o)->front)();
  else   (((::std::vector<OpNovicePMTHit*>*)o)->front)();
}

static  void method_6733( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNovicePMTHit*>*)o)->front)();
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->front)();
}

static  void method_6734( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::vector<OpNovicePMTHit*>*)o)->back)();
  else   (((::std::vector<OpNovicePMTHit*>*)o)->back)();
}

static  void method_6735( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::vector<OpNovicePMTHit*>*)o)->back)();
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->back)();
}

static  void method_6736( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((::std::vector<OpNovicePMTHit*>*)o)->data)());
  else   (((::std::vector<OpNovicePMTHit*>*)o)->data)();
}

static  void method_6737( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::std::vector<OpNovicePMTHit*>*)o)->data)());
  else   (((const ::std::vector<OpNovicePMTHit*>*)o)->data)();
}

static  void method_6738( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->push_back)(*(::OpNovicePMTHit* const*)arg[0]);
}

static  void method_6739( void*, void* o, const std::vector<void*>&, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->pop_back)();
}

static  void method_6740( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >)((((::std::vector<OpNovicePMTHit*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0],
    *(::OpNovicePMTHit* const*)arg[1]));
  else   (((::std::vector<OpNovicePMTHit*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0],
    *(::OpNovicePMTHit* const*)arg[1]);
}

static  void method_6741( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0],
    *(::size_t*)arg[1],
    *(::OpNovicePMTHit* const*)arg[2]);
}

static  void method_6742( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >)((((::std::vector<OpNovicePMTHit*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0]));
  else   (((::std::vector<OpNovicePMTHit*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0]);
}

static  void method_6743( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >)((((::std::vector<OpNovicePMTHit*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[1]));
  else   (((::std::vector<OpNovicePMTHit*>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<OpNovicePMTHit**,std::vector<OpNovicePMTHit*> >*)arg[1]);
}

static  void method_6744( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->swap)(*(::std::vector<OpNovicePMTHit*>*)arg[0]);
}

static  void method_6745( void*, void* o, const std::vector<void*>&, void*)
{
  (((::std::vector<OpNovicePMTHit*>*)o)->clear)();
}

static void constructor_x13( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::vector<OpNovicePMTHit*>();
  else ::new(mem) ::std::vector<OpNovicePMTHit*>();
}

static void method_newdel_2246( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::std::vector<OpNovicePMTHit*> >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::std::vector<OpNovicePMTHit*> >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::std::vector<OpNovicePMTHit*> >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::std::vector<OpNovicePMTHit*> >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::std::vector<OpNovicePMTHit*> >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

static void method_x15( void* retaddr, void*, const std::vector<void*>&, void*)
{
  typedef std::vector<std::pair< ::Reflex::Base, int> > Bases_t;
  static Bases_t s_bases;
  if ( !s_bases.size() ) {
    s_bases.push_back(std::make_pair(::Reflex::Base( ::Reflex::TypeBuilder(Reflex::Literal("std::_Vector_base<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> >")), ::Reflex::BaseOffset< ::std::vector<OpNovicePMTHit*>,::std::_Vector_base<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > >::Get(),::Reflex::PROTECTED), 0));
  }
  if (retaddr) *(Bases_t**)retaddr = &s_bases;
}

static void method_x16( void* retaddr, void*, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**) retaddr = ::Reflex::Proxy< ::std::vector<OpNovicePMTHit*> >::Generate();
  else ::Reflex::Proxy< ::std::vector<OpNovicePMTHit*> >::Generate();
}

//------Dictionary for class vector<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > -------------------------------
void __std__vector_OpNovicePMTHitp__db_datamem(Reflex::Class*);
void __std__vector_OpNovicePMTHitp__db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __std__vector_OpNovicePMTHitp__datamem_bld(&__std__vector_OpNovicePMTHitp__db_datamem);
Reflex::GenreflexMemberBuilder __std__vector_OpNovicePMTHitp__funcmem_bld(&__std__vector_OpNovicePMTHitp__db_funcmem);
void __std__vector_OpNovicePMTHitp__dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("std::vector<OpNovicePMTHit*>"), typeid(::std::vector<OpNovicePMTHit*>), sizeof(::std::vector<OpNovicePMTHit*>), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL, ::Reflex::CLASS)
  .AddBase(type_2604, ::Reflex::BaseOffset< ::std::vector<OpNovicePMTHit*>, ::std::_Vector_base<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > >::Get(), ::Reflex::PROTECTED)
  .AddTypedef(type_4809, Reflex::Literal("std::vector<OpNovicePMTHit*>::_Alloc_value_type"))
  .AddTypedef(type_2604, Reflex::Literal("std::vector<OpNovicePMTHit*>::_Base"))
  .AddTypedef(type_2398, Reflex::Literal("std::vector<OpNovicePMTHit*>::_Tp_alloc_type"))
  .AddTypedef(type_4809, Reflex::Literal("std::vector<OpNovicePMTHit*>::value_type"))
  .AddTypedef(type_6692, Reflex::Literal("std::vector<OpNovicePMTHit*>::pointer"))
  .AddTypedef(type_6694, Reflex::Literal("std::vector<OpNovicePMTHit*>::const_pointer"))
  .AddTypedef(type_6696, Reflex::Literal("std::vector<OpNovicePMTHit*>::reference"))
  .AddTypedef(type_6698, Reflex::Literal("std::vector<OpNovicePMTHit*>::const_reference"))
  .AddTypedef(type_3153, Reflex::Literal("std::vector<OpNovicePMTHit*>::iterator"))
  .AddTypedef(type_3154, Reflex::Literal("std::vector<OpNovicePMTHit*>::const_iterator"))
  .AddTypedef(type_2508, Reflex::Literal("std::vector<OpNovicePMTHit*>::const_reverse_iterator"))
  .AddTypedef(type_2509, Reflex::Literal("std::vector<OpNovicePMTHit*>::reverse_iterator"))
  .AddTypedef(type_1343, Reflex::Literal("std::vector<OpNovicePMTHit*>::size_type"))
  .AddTypedef(type_1043, Reflex::Literal("std::vector<OpNovicePMTHit*>::difference_type"))
  .AddTypedef(type_2398, Reflex::Literal("std::vector<OpNovicePMTHit*>::allocator_type"))
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_11147), Reflex::Literal("vector"), constructor_6707, 0, "__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_1343, type_6698, type_11147), Reflex::Literal("vector"), constructor_6708, 0, "__n;__value=_Tp();__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_11148), Reflex::Literal("vector"), constructor_6709, 0, "__x", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~vector"), destructor_6710, 0, 0, ::Reflex::PUBLIC | ::Reflex::DESTRUCTOR )
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("vector"), constructor_x13, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_2246, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getBasesTable"), method_x15, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddFunctionMember<void*(void)>(Reflex::Literal("createCollFuncTable"), method_x16, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandFunctionMemberBuilder(&__std__vector_OpNovicePMTHitp__funcmem_bld);
}

//------Delayed data member builder for class vector<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > -------------------
void __std__vector_OpNovicePMTHitp__db_datamem(Reflex::Class*) {

}
//------Delayed function member builder for class vector<OpNovicePMTHit*,std::allocator<OpNovicePMTHit*> > -------------------
void __std__vector_OpNovicePMTHitp__db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_11149, type_11148), Reflex::Literal("operator="), operator_6711, 0, "__x", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343, type_6698), Reflex::Literal("assign"), method_6712, 0, "__n;__val", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3153), Reflex::Literal("begin"), method_6713, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3154), Reflex::Literal("begin"), method_6714, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3153), Reflex::Literal("end"), method_6715, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3154), Reflex::Literal("end"), method_6716, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("size"), method_6721, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("max_size"), method_6722, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343, type_4809), Reflex::Literal("resize"), method_6723, 0, "__new_size;__x=_Tp()", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("capacity"), method_6724, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898), Reflex::Literal("empty"), method_6725, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343), Reflex::Literal("reserve"), method_6726, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6696, type_1343), Reflex::Literal("operator[]"), operator_6727, 0, "__n", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6698, type_1343), Reflex::Literal("operator[]"), operator_6728, 0, "__n", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6696, type_1343), Reflex::Literal("at"), method_6730, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6698, type_1343), Reflex::Literal("at"), method_6731, 0, "__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6696), Reflex::Literal("front"), method_6732, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6698), Reflex::Literal("front"), method_6733, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6696), Reflex::Literal("back"), method_6734, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6698), Reflex::Literal("back"), method_6735, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6692), Reflex::Literal("data"), method_6736, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6694), Reflex::Literal("data"), method_6737, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_6698), Reflex::Literal("push_back"), method_6738, 0, "__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("pop_back"), method_6739, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3153, type_3153, type_6698), Reflex::Literal("insert"), method_6740, 0, "__position;__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_3153, type_1343, type_6698), Reflex::Literal("insert"), method_6741, 0, "__position;__n;__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3153, type_3153), Reflex::Literal("erase"), method_6742, 0, "__position", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3153, type_3153, type_3153), Reflex::Literal("erase"), method_6743, 0, "__first;__last", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_11149), Reflex::Literal("swap"), method_6744, 0, "__x", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("clear"), method_6745, 0, 0, ::Reflex::PUBLIC);
}
//------Stub functions for class basic_string<char,std::char_traits<char>,std::allocator<char> > -------------------------------
static void constructor_7185( void* retaddr, void* mem, const std::vector<void*>&, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>();
  else ::new(mem) ::std::basic_string<char>();
}

static void constructor_7186( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(const ::std::allocator<char>*)arg[0]);
  else ::new(mem) ::std::basic_string<char>(*(const ::std::allocator<char>*)arg[0]);
}

static void constructor_7187( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0]);
  else ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0]);
}

static void constructor_7188( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 2 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  else ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2]);
  else ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2]);
  }
}

static void constructor_7189( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2],
      *(const ::std::allocator<char>*)arg[3]);
  else ::new(mem) ::std::basic_string<char>(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2],
      *(const ::std::allocator<char>*)arg[3]);
}

static void constructor_7190( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 2 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(::size_t*)arg[1]);
  else ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(::size_t*)arg[1],
      *(const ::std::allocator<char>*)arg[2]);
  else ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(::size_t*)arg[1],
      *(const ::std::allocator<char>*)arg[2]);
  }
}

static void constructor_7191( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 1 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>((const char*)arg[0]);
  else ::new(mem) ::std::basic_string<char>((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(const ::std::allocator<char>*)arg[1]);
  else ::new(mem) ::std::basic_string<char>((const char*)arg[0],
      *(const ::std::allocator<char>*)arg[1]);
  }
}

static void constructor_7192( void* retaddr, void* mem, const std::vector<void*>& arg, void*) {
  if ( arg.size() == 2 ) {
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(::size_t*)arg[0],
      *(char*)arg[1]);
  else ::new(mem) ::std::basic_string<char>(*(::size_t*)arg[0],
      *(char*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) *(void**)retaddr = ::new(mem) ::std::basic_string<char>(*(::size_t*)arg[0],
      *(char*)arg[1],
      *(const ::std::allocator<char>*)arg[2]);
  else ::new(mem) ::std::basic_string<char>(*(::size_t*)arg[0],
      *(char*)arg[1],
      *(const ::std::allocator<char>*)arg[2]);
  }
}

static void destructor_7193(void*, void * o, const std::vector<void*>&, void *) {
(((::std::basic_string<char>*)o)->::std::basic_string<char>::~basic_string)();
}
static  void operator_7194( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator=)(*(const ::std::basic_string<char>*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator=)(*(const ::std::basic_string<char>*)arg[0]);
}

static  void operator_7195( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator=)((const char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator=)((const char*)arg[0]);
}

static  void operator_7196( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator=)(*(char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator=)(*(char*)arg[0]);
}

static  void method_7197( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >)((((::std::basic_string<char>*)o)->begin)());
  else   (((::std::basic_string<char>*)o)->begin)();
}

static  void method_7198( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >)((((const ::std::basic_string<char>*)o)->begin)());
  else   (((const ::std::basic_string<char>*)o)->begin)();
}

static  void method_7199( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >)((((::std::basic_string<char>*)o)->end)());
  else   (((::std::basic_string<char>*)o)->end)();
}

static  void method_7200( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >)((((const ::std::basic_string<char>*)o)->end)());
  else   (((const ::std::basic_string<char>*)o)->end)();
}

static  void method_7205( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->size)());
  else   (((const ::std::basic_string<char>*)o)->size)();
}

static  void method_7206( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->length)());
  else   (((const ::std::basic_string<char>*)o)->length)();
}

static  void method_7207( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->max_size)());
  else   (((const ::std::basic_string<char>*)o)->max_size)();
}

static  void method_7208( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::basic_string<char>*)o)->resize)(*(::size_t*)arg[0],
    *(char*)arg[1]);
}

static  void method_7209( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::basic_string<char>*)o)->resize)(*(::size_t*)arg[0]);
}

static  void method_7210( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->capacity)());
  else   (((const ::std::basic_string<char>*)o)->capacity)();
}

static  void method_7211( void*, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 0 ) {
    (((::std::basic_string<char>*)o)->reserve)();
  }
  else if ( arg.size() == 1 ) { 
    (((::std::basic_string<char>*)o)->reserve)(*(::size_t*)arg[0]);
  }
}

static  void method_7212( void*, void* o, const std::vector<void*>&, void*)
{
  (((::std::basic_string<char>*)o)->clear)();
}

static  void method_7213( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (bool)((((const ::std::basic_string<char>*)o)->empty)());
  else   (((const ::std::basic_string<char>*)o)->empty)();
}

static  void operator_7214( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::basic_string<char>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((const ::std::basic_string<char>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void operator_7215( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator[])(*(::size_t*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator[])(*(::size_t*)arg[0]);
}

static  void method_7216( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((const ::std::basic_string<char>*)o)->at)(*(::size_t*)arg[0]);
  else   (((const ::std::basic_string<char>*)o)->at)(*(::size_t*)arg[0]);
}

static  void method_7217( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->at)(*(::size_t*)arg[0]);
  else   (((::std::basic_string<char>*)o)->at)(*(::size_t*)arg[0]);
}

static  void operator_7218( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator+=)(*(const ::std::basic_string<char>*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator+=)(*(const ::std::basic_string<char>*)arg[0]);
}

static  void operator_7219( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator+=)((const char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator+=)((const char*)arg[0]);
}

static  void operator_7220( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->operator+=)(*(char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->operator+=)(*(char*)arg[0]);
}

static  void method_7221( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->append)(*(const ::std::basic_string<char>*)arg[0]);
  else   (((::std::basic_string<char>*)o)->append)(*(const ::std::basic_string<char>*)arg[0]);
}

static  void method_7222( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->append)(*(const ::std::basic_string<char>*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
  else   (((::std::basic_string<char>*)o)->append)(*(const ::std::basic_string<char>*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7223( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->append)((const char*)arg[0],
    *(::size_t*)arg[1]);
  else   (((::std::basic_string<char>*)o)->append)((const char*)arg[0],
    *(::size_t*)arg[1]);
}

static  void method_7224( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->append)((const char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->append)((const char*)arg[0]);
}

static  void method_7225( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->append)(*(::size_t*)arg[0],
    *(char*)arg[1]);
  else   (((::std::basic_string<char>*)o)->append)(*(::size_t*)arg[0],
    *(char*)arg[1]);
}

static  void method_7226( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::basic_string<char>*)o)->push_back)(*(char*)arg[0]);
}

static  void method_7227( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->assign)(*(const ::std::basic_string<char>*)arg[0]);
  else   (((::std::basic_string<char>*)o)->assign)(*(const ::std::basic_string<char>*)arg[0]);
}

static  void method_7228( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->assign)(*(const ::std::basic_string<char>*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
  else   (((::std::basic_string<char>*)o)->assign)(*(const ::std::basic_string<char>*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7229( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->assign)((const char*)arg[0],
    *(::size_t*)arg[1]);
  else   (((::std::basic_string<char>*)o)->assign)((const char*)arg[0],
    *(::size_t*)arg[1]);
}

static  void method_7230( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->assign)((const char*)arg[0]);
  else   (((::std::basic_string<char>*)o)->assign)((const char*)arg[0]);
}

static  void method_7231( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->assign)(*(::size_t*)arg[0],
    *(char*)arg[1]);
  else   (((::std::basic_string<char>*)o)->assign)(*(::size_t*)arg[0],
    *(char*)arg[1]);
}

static  void method_7232( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::basic_string<char>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::size_t*)arg[1],
    *(char*)arg[2]);
}

static  void method_7233( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(const ::std::basic_string<char>*)arg[1]);
  else   (((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(const ::std::basic_string<char>*)arg[1]);
}

static  void method_7234( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(const ::std::basic_string<char>*)arg[1],
    *(::size_t*)arg[2],
    *(::size_t*)arg[3]);
  else   (((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(const ::std::basic_string<char>*)arg[1],
    *(::size_t*)arg[2],
    *(::size_t*)arg[3]);
}

static  void method_7235( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    (const char*)arg[1],
    *(::size_t*)arg[2]);
  else   (((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    (const char*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7236( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    (const char*)arg[1]);
  else   (((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    (const char*)arg[1]);
}

static  void method_7237( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(char*)arg[2]);
  else   (((::std::basic_string<char>*)o)->insert)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(char*)arg[2]);
}

static  void method_7238( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >)((((::std::basic_string<char>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(char*)arg[1]));
  else   (((::std::basic_string<char>*)o)->insert)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(char*)arg[1]);
}

static  void method_7239( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 0 ) {
    if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->erase)();
    else     (((::std::basic_string<char>*)o)->erase)();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->erase)(*(::size_t*)arg[0]);
    else     (((::std::basic_string<char>*)o)->erase)(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->erase)(*(::size_t*)arg[0],
      *(::size_t*)arg[1]);
    else     (((::std::basic_string<char>*)o)->erase)(*(::size_t*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7240( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >)((((::std::basic_string<char>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0]));
  else   (((::std::basic_string<char>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0]);
}

static  void method_7241( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >)((((::std::basic_string<char>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1]));
  else   (((::std::basic_string<char>*)o)->erase)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1]);
}

static  void method_7242( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]);
}

static  void method_7243( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2],
    *(::size_t*)arg[3],
    *(::size_t*)arg[4]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2],
    *(::size_t*)arg[3],
    *(::size_t*)arg[4]);
}

static  void method_7244( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]);
}

static  void method_7245( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2]);
}

static  void method_7246( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2],
    *(char*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2],
    *(char*)arg[3]);
}

static  void method_7247( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]);
}

static  void method_7248( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]);
}

static  void method_7249( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2]);
}

static  void method_7250( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::size_t*)arg[2],
    *(char*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::size_t*)arg[2],
    *(char*)arg[3]);
}

static  void method_7251( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (char*)arg[2],
    (char*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (char*)arg[2],
    (char*)arg[3]);
}

static  void method_7252( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2],
    (const char*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    (const char*)arg[2],
    (const char*)arg[3]);
}

static  void method_7253( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[2],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[2],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[3]);
}

static  void method_7254( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) *(void**)retaddr = (void*)&(((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >*)arg[2],
    *(::__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >*)arg[3]);
  else   (((::std::basic_string<char>*)o)->replace)(*(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[0],
    *(::__gnu_cxx::__normal_iterator<char*,std::basic_string<char> >*)arg[1],
    *(::__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >*)arg[2],
    *(::__gnu_cxx::__normal_iterator<const char*,std::basic_string<char> >*)arg[3]);
}

static  void method_7258( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 2 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->copy)((char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->copy)((char*)arg[0],
      *(::size_t*)arg[1]);
  }
  else if ( arg.size() == 3 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->copy)((char*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2]));
    else     (((const ::std::basic_string<char>*)o)->copy)((char*)arg[0],
      *(::size_t*)arg[1],
      *(::size_t*)arg[2]);
  }
}

static  void method_7259( void*, void* o, const std::vector<void*>& arg, void*)
{
  (((::std::basic_string<char>*)o)->swap)(*(::std::basic_string<char>*)arg[0]);
}

static  void method_7260( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::std::basic_string<char>*)o)->c_str)());
  else   (((const ::std::basic_string<char>*)o)->c_str)();
}

static  void method_7261( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) *(void**)retaddr = Reflex::FuncToVoidPtr((((const ::std::basic_string<char>*)o)->data)());
  else   (((const ::std::basic_string<char>*)o)->data)();
}

static  void method_7262( void* retaddr, void* o, const std::vector<void*>&, void*)
{
  if (retaddr) new (retaddr) (std::allocator<char>)((((const ::std::basic_string<char>*)o)->get_allocator)());
  else   (((const ::std::basic_string<char>*)o)->get_allocator)();
}

static  void method_7263( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->find)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7264( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7265( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7266( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7267( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->rfind)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->rfind)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7268( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7269( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->rfind)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7270( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->rfind)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->rfind)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->rfind)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7271( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7272( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7273( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7274( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_of)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_of)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7275( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7276( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7277( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7278( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_of)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_of)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7279( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7280( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7281( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7282( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_first_not_of)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_first_not_of)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7283( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)(*(const ::std::basic_string<char>*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)(*(const ::std::basic_string<char>*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)(*(const ::std::basic_string<char>*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7284( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0],
    *(::size_t*)arg[1],
    *(::size_t*)arg[2]);
}

static  void method_7285( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)((const char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7286( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 1 ) {
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)(*(char*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)(*(char*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (size_t)((((const ::std::basic_string<char>*)o)->find_last_not_of)(*(char*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->find_last_not_of)(*(char*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7287( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if ( arg.size() == 0 ) {
    if (retaddr) new (retaddr) (std::basic_string<char>)((((const ::std::basic_string<char>*)o)->substr)());
    else     (((const ::std::basic_string<char>*)o)->substr)();
  }
  else if ( arg.size() == 1 ) { 
    if (retaddr) new (retaddr) (std::basic_string<char>)((((const ::std::basic_string<char>*)o)->substr)(*(::size_t*)arg[0]));
    else     (((const ::std::basic_string<char>*)o)->substr)(*(::size_t*)arg[0]);
  }
  else if ( arg.size() == 2 ) { 
    if (retaddr) new (retaddr) (std::basic_string<char>)((((const ::std::basic_string<char>*)o)->substr)(*(::size_t*)arg[0],
      *(::size_t*)arg[1]));
    else     (((const ::std::basic_string<char>*)o)->substr)(*(::size_t*)arg[0],
      *(::size_t*)arg[1]);
  }
}

static  void method_7288( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)(*(const ::std::basic_string<char>*)arg[0]));
  else   (((const ::std::basic_string<char>*)o)->compare)(*(const ::std::basic_string<char>*)arg[0]);
}

static  void method_7289( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2]);
}

static  void method_7290( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2],
    *(::size_t*)arg[3],
    *(::size_t*)arg[4]));
  else   (((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    *(const ::std::basic_string<char>*)arg[2],
    *(::size_t*)arg[3],
    *(::size_t*)arg[4]);
}

static  void method_7291( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)((const char*)arg[0]));
  else   (((const ::std::basic_string<char>*)o)->compare)((const char*)arg[0]);
}

static  void method_7292( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2]));
  else   (((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2]);
}

static  void method_7293( void* retaddr, void* o, const std::vector<void*>& arg, void*)
{
  if (retaddr) new (retaddr) (int)((((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]));
  else   (((const ::std::basic_string<char>*)o)->compare)(*(::size_t*)arg[0],
    *(::size_t*)arg[1],
    (const char*)arg[2],
    *(::size_t*)arg[3]);
}

static void method_newdel_2265( void* retaddr, void*, const std::vector<void*>&, void*)
{
  static ::Reflex::NewDelFunctions s_funcs;
  s_funcs.fNew         = ::Reflex::NewDelFunctionsT< ::std::basic_string<char> >::new_T;
  s_funcs.fNewArray    = ::Reflex::NewDelFunctionsT< ::std::basic_string<char> >::newArray_T;
  s_funcs.fDelete      = ::Reflex::NewDelFunctionsT< ::std::basic_string<char> >::delete_T;
  s_funcs.fDeleteArray = ::Reflex::NewDelFunctionsT< ::std::basic_string<char> >::deleteArray_T;
  s_funcs.fDestructor  = ::Reflex::NewDelFunctionsT< ::std::basic_string<char> >::destruct_T;
  if (retaddr) *(::Reflex::NewDelFunctions**)retaddr = &s_funcs;
}

//------Dictionary for class basic_string<char,std::char_traits<char>,std::allocator<char> > -------------------------------
void __std__basic_string_char__db_datamem(Reflex::Class*);
void __std__basic_string_char__db_funcmem(Reflex::Class*);
Reflex::GenreflexMemberBuilder __std__basic_string_char__datamem_bld(&__std__basic_string_char__db_datamem);
Reflex::GenreflexMemberBuilder __std__basic_string_char__funcmem_bld(&__std__basic_string_char__db_funcmem);
void __std__basic_string_char__dict() {
  ::Reflex::ClassBuilder(Reflex::Literal("std::basic_string<char>"), typeid(::std::basic_string<char>), sizeof(::std::basic_string<char>), ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL, ::Reflex::STRUCT)
  .AddTypedef(type_2409, Reflex::Literal("std::basic_string<char>::_CharT_alloc_type"))
  .AddTypedef(type_2458, Reflex::Literal("std::basic_string<char>::traits_type"))
  .AddTypedef(type_302, Reflex::Literal("std::basic_string<char>::value_type"))
  .AddTypedef(type_2409, Reflex::Literal("std::basic_string<char>::allocator_type"))
  .AddTypedef(type_1343, Reflex::Literal("std::basic_string<char>::size_type"))
  .AddTypedef(type_1043, Reflex::Literal("std::basic_string<char>::difference_type"))
  .AddTypedef(type_6588, Reflex::Literal("std::basic_string<char>::reference"))
  .AddTypedef(type_7154, Reflex::Literal("std::basic_string<char>::const_reference"))
  .AddTypedef(type_724, Reflex::Literal("std::basic_string<char>::pointer"))
  .AddTypedef(type_2727, Reflex::Literal("std::basic_string<char>::const_pointer"))
  .AddTypedef(type_3167, Reflex::Literal("std::basic_string<char>::iterator"))
  .AddTypedef(type_3170, Reflex::Literal("std::basic_string<char>::const_iterator"))
  .AddTypedef(type_2528, Reflex::Literal("std::basic_string<char>::const_reverse_iterator"))
  .AddTypedef(type_2529, Reflex::Literal("std::basic_string<char>::reverse_iterator"))
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("basic_string"), constructor_7185, 0, 0, ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_11214), Reflex::Literal("basic_string"), constructor_7186, 0, "__a", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_8771), Reflex::Literal("basic_string"), constructor_7187, 0, "__str", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_8771, type_1343, type_1343), Reflex::Literal("basic_string"), constructor_7188, 0, "__str;__pos;__n=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_8771, type_1343, type_1343, type_11214), Reflex::Literal("basic_string"), constructor_7189, 0, "__str;__pos;__n;__a", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_2727, type_1343, type_11214), Reflex::Literal("basic_string"), constructor_7190, 0, "__s;__n;__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_2727, type_11214), Reflex::Literal("basic_string"), constructor_7191, 0, "__s;__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void, type_1343, type_302, type_11214), Reflex::Literal("basic_string"), constructor_7192, 0, "__n;__c;__a=_Alloc()", ::Reflex::PUBLIC | ::Reflex::EXPLICIT | ::Reflex::CONSTRUCTOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_void), Reflex::Literal("~basic_string"), destructor_7193, 0, 0, ::Reflex::PUBLIC | ::Reflex::DESTRUCTOR )
  .AddFunctionMember<void*(void)>(Reflex::Literal("__getNewDelFunctions"), method_newdel_2265, 0, 0, ::Reflex::PUBLIC | ::Reflex::ARTIFICIAL)
  .AddOnDemandDataMemberBuilder(&__std__basic_string_char__datamem_bld)
  .AddOnDemandFunctionMemberBuilder(&__std__basic_string_char__funcmem_bld);
}

//------Delayed data member builder for class basic_string<char,std::char_traits<char>,std::allocator<char> > -------------------
void __std__basic_string_char__db_datamem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddDataMember(type_7164, Reflex::Literal("_M_dataplus"), OffsetOf(__shadow__::__std__basic_string_char_, _M_dataplus), ::Reflex::PRIVATE | ::Reflex::MUTABLE);
}
//------Delayed function member builder for class basic_string<char,std::char_traits<char>,std::allocator<char> > -------------------
void __std__basic_string_char__db_funcmem(Reflex::Class* cl) {
  ::Reflex::ClassBuilder(cl)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771), Reflex::Literal("operator="), operator_7194, 0, "__str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727), Reflex::Literal("operator="), operator_7195, 0, "__s", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_302), Reflex::Literal("operator="), operator_7196, 0, "__c", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3167), Reflex::Literal("begin"), method_7197, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3170), Reflex::Literal("begin"), method_7198, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3167), Reflex::Literal("end"), method_7199, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3170), Reflex::Literal("end"), method_7200, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("size"), method_7205, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("length"), method_7206, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("max_size"), method_7207, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343, type_302), Reflex::Literal("resize"), method_7208, 0, "__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343), Reflex::Literal("resize"), method_7209, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343), Reflex::Literal("capacity"), method_7210, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_1343), Reflex::Literal("reserve"), method_7211, 0, "__res=0", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686), Reflex::Literal("clear"), method_7212, 0, 0, ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_898), Reflex::Literal("empty"), method_7213, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_7154, type_1343), Reflex::Literal("operator[]"), operator_7214, 0, "__pos", ::Reflex::PUBLIC | ::Reflex::OPERATOR | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6588, type_1343), Reflex::Literal("operator[]"), operator_7215, 0, "__pos", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_7154, type_1343), Reflex::Literal("at"), method_7216, 0, "__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_6588, type_1343), Reflex::Literal("at"), method_7217, 0, "__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771), Reflex::Literal("operator+="), operator_7218, 0, "__str", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727), Reflex::Literal("operator+="), operator_7219, 0, "__s", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_302), Reflex::Literal("operator+="), operator_7220, 0, "__c", ::Reflex::PUBLIC | ::Reflex::OPERATOR)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771), Reflex::Literal("append"), method_7221, 0, "__str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771, type_1343, type_1343), Reflex::Literal("append"), method_7222, 0, "__str;__pos;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727, type_1343), Reflex::Literal("append"), method_7223, 0, "__s;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727), Reflex::Literal("append"), method_7224, 0, "__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_302), Reflex::Literal("append"), method_7225, 0, "__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_302), Reflex::Literal("push_back"), method_7226, 0, "__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771), Reflex::Literal("assign"), method_7227, 0, "__str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_8771, type_1343, type_1343), Reflex::Literal("assign"), method_7228, 0, "__str;__pos;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727, type_1343), Reflex::Literal("assign"), method_7229, 0, "__s;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_2727), Reflex::Literal("assign"), method_7230, 0, "__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_302), Reflex::Literal("assign"), method_7231, 0, "__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_3167, type_1343, type_302), Reflex::Literal("insert"), method_7232, 0, "__p;__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_8771), Reflex::Literal("insert"), method_7233, 0, "__pos1;__str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_8771, type_1343, type_1343), Reflex::Literal("insert"), method_7234, 0, "__pos1;__str;__pos2;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_2727, type_1343), Reflex::Literal("insert"), method_7235, 0, "__pos;__s;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_2727), Reflex::Literal("insert"), method_7236, 0, "__pos;__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_302), Reflex::Literal("insert"), method_7237, 0, "__pos;__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3167, type_3167, type_302), Reflex::Literal("insert"), method_7238, 0, "__p;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343), Reflex::Literal("erase"), method_7239, 0, "__pos=0;__n=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3167, type_3167), Reflex::Literal("erase"), method_7240, 0, "__position", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_3167, type_3167, type_3167), Reflex::Literal("erase"), method_7241, 0, "__first;__last", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_8771), Reflex::Literal("replace"), method_7242, 0, "__pos;__n;__str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_8771, type_1343, type_1343), Reflex::Literal("replace"), method_7243, 0, "__pos1;__n1;__str;__pos2;__n2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_2727, type_1343), Reflex::Literal("replace"), method_7244, 0, "__pos;__n1;__s;__n2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_2727), Reflex::Literal("replace"), method_7245, 0, "__pos;__n1;__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_1343, type_1343, type_1343, type_302), Reflex::Literal("replace"), method_7246, 0, "__pos;__n1;__n2;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_8771), Reflex::Literal("replace"), method_7247, 0, "__i1;__i2;__str", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_2727, type_1343), Reflex::Literal("replace"), method_7248, 0, "__i1;__i2;__s;__n", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_2727), Reflex::Literal("replace"), method_7249, 0, "__i1;__i2;__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_1343, type_302), Reflex::Literal("replace"), method_7250, 0, "__i1;__i2;__n;__c", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_724, type_724), Reflex::Literal("replace"), method_7251, 0, "__i1;__i2;__k1;__k2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_2727, type_2727), Reflex::Literal("replace"), method_7252, 0, "__i1;__i2;__k1;__k2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_3167, type_3167), Reflex::Literal("replace"), method_7253, 0, "__i1;__i2;__k1;__k2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_8639, type_3167, type_3167, type_3170, type_3170), Reflex::Literal("replace"), method_7254, 0, "__i1;__i2;__k1;__k2", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_724, type_1343, type_1343), Reflex::Literal("copy"), method_7258, 0, "__s;__n;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_686, type_8639), Reflex::Literal("swap"), method_7259, 0, "__s", ::Reflex::PUBLIC)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2727), Reflex::Literal("c_str"), method_7260, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2727), Reflex::Literal("data"), method_7261, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2409), Reflex::Literal("get_allocator"), method_7262, 0, 0, ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("find"), method_7263, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("find"), method_7264, 0, "__str;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("find"), method_7265, 0, "__s;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("find"), method_7266, 0, "__c;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("rfind"), method_7267, 0, "__str;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("rfind"), method_7268, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("rfind"), method_7269, 0, "__s;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("rfind"), method_7270, 0, "__c;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("find_first_of"), method_7271, 0, "__str;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("find_first_of"), method_7272, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("find_first_of"), method_7273, 0, "__s;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("find_first_of"), method_7274, 0, "__c;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("find_last_of"), method_7275, 0, "__str;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("find_last_of"), method_7276, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("find_last_of"), method_7277, 0, "__s;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("find_last_of"), method_7278, 0, "__c;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("find_first_not_of"), method_7279, 0, "__str;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("find_first_not_of"), method_7280, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("find_first_not_of"), method_7281, 0, "__s;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("find_first_not_of"), method_7282, 0, "__c;__pos=0", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_8771, type_1343), Reflex::Literal("find_last_not_of"), method_7283, 0, "__str;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343, type_1343), Reflex::Literal("find_last_not_of"), method_7284, 0, "__s;__pos;__n", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_2727, type_1343), Reflex::Literal("find_last_not_of"), method_7285, 0, "__s;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_1343, type_302, type_1343), Reflex::Literal("find_last_not_of"), method_7286, 0, "__c;__pos=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_2265, type_1343, type_1343), Reflex::Literal("substr"), method_7287, 0, "__pos=0;__n=std::basic_string<_CharT, _Traits, _Alloc>::npos", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_8771), Reflex::Literal("compare"), method_7288, 0, "__str", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_1343, type_1343, type_8771), Reflex::Literal("compare"), method_7289, 0, "__pos;__n;__str", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_1343, type_1343, type_8771, type_1343, type_1343), Reflex::Literal("compare"), method_7290, 0, "__pos1;__n1;__str;__pos2;__n2", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_2727), Reflex::Literal("compare"), method_7291, 0, "__s", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_1343, type_1343, type_2727), Reflex::Literal("compare"), method_7292, 0, "__pos;__n1;__s", ::Reflex::PUBLIC | ::Reflex::CONST)
  .AddFunctionMember(::Reflex::FunctionTypeBuilder(type_43, type_1343, type_1343, type_2727, type_1343), Reflex::Literal("compare"), method_7293, 0, "__pos;__n1;__s;__n2", ::Reflex::PUBLIC | ::Reflex::CONST);
}
namespace {
  struct Dictionaries {
    Dictionaries() {
      Reflex::Instance initialize_reflex;
      __OpNoviceDigi_dict(); 
      __G4VDigi_dict(); 
      __G4VHit_dict(); 
      __CLHEP__Hep3Vector_dict(); 
      __OpNovicePMTHit_dict(); 
      __G4String_dict(); 
      __std__vector_OpNoviceDigip__dict(); 
      __std__vector_OpNovicePMTHitp__dict(); 
      __std__basic_string_char__dict(); 
    }
    ~Dictionaries() {
      type_448.Unload(); // class OpNoviceDigi 
      type_944.Unload(); // class G4VDigi 
      type_1000.Unload(); // class G4VHit 
      type_1335.Unload(); // class CLHEP::Hep3Vector 
      type_1537.Unload(); // class OpNovicePMTHit 
      type_2064.Unload(); // class G4String 
      type_2245.Unload(); // class std::vector<OpNoviceDigi*> 
      type_2246.Unload(); // class std::vector<OpNovicePMTHit*> 
      type_2265.Unload(); // class std::basic_string<char> 
    }
  };
  static Dictionaries instance;
}
} // unnamed namespace
