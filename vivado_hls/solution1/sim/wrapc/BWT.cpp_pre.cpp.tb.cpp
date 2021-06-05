// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "G:/Repo/hls_project/src/BWT.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "G:/Repo/hls_project/src/BWT.cpp"
# 27 "G:/Repo/hls_project/src/BWT.cpp"
# 1 "G:/Repo/hls_project/src/BWT.h" 1
# 31 "G:/Repo/hls_project/src/BWT.h"
extern "C" {


# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/assert.h" 1 3
# 15 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/assert.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 1 3
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 1 3
# 12 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
# 88 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3
             
# 97 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_mac.h" 3
             
# 13 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 1 3
# 44 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 3

# 44 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_secapi.h" 3
extern "C++" {
template <bool __test, typename __dsttype>
  struct __if_array;
template <typename __dsttype>
  struct __if_array <true, __dsttype> {
    typedef __dsttype __type;
};
}
# 14 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3
# 275 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 1 3
# 9 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 1 3
# 565 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 566 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 567 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 2 3




#pragma pack(push,_CRT_PACKING)



extern "C" {





  typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 99 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/vadefs.h" 3
}



#pragma pack(pop)
# 276 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 2 3
# 534 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw.h" 3
extern "C" {




void __attribute__((__cdecl__)) __debugbreak(void);
extern __inline__ __attribute__((__always_inline__,__gnu_inline__)) void __attribute__((__cdecl__)) __debugbreak(void)
{
  __asm__ __volatile__("int {$}3":);
}




const char *__mingw_get_crt_info (void);


}
# 11 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 2 3




#pragma pack(push,_CRT_PACKING)
# 35 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
__extension__ typedef unsigned long long size_t;
# 45 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
__extension__ typedef long long ssize_t;






typedef size_t rsize_t;
# 62 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
__extension__ typedef long long intptr_t;
# 75 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
__extension__ typedef unsigned long long uintptr_t;
# 88 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
__extension__ typedef long long ptrdiff_t;
# 106 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
typedef unsigned short wint_t;
typedef unsigned short wctype_t;





typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;
# 138 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
typedef __time64_t time_t;
# 422 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/crtdefs.h" 3
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;







#pragma pack(pop)
# 16 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/assert.h" 2 3

# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 1 3
# 36 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 1 3
# 39 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3
       
# 40 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3

# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 1 3
# 196 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 3
namespace std
{
  typedef long long unsigned int size_t;
  typedef long long int ptrdiff_t;


  typedef decltype(nullptr) nullptr_t;

}
# 218 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 3
namespace std
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
namespace __gnu_cxx
{
  inline namespace __cxx11 __attribute__((__abi_tag__ ("cxx11"))) { }
}
# 495 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/os_defines.h" 1 3
# 496 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 2 3


# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/cpu_defines.h" 1 3
# 499 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/x86_64-w64-mingw32/bits/c++config.h" 2 3
# 42 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 2 3
# 75 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 1 3
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 1 3 4
# 34 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 3 4
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/syslimits.h" 1 3 4






# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 1 3 4
# 168 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 3 4
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/limits.h" 1 3 4
# 169 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 2 3 4
# 8 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/syslimits.h" 2 3 4
# 35 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include-fixed/limits.h" 2 3 4
# 11 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 2 3
# 25 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
#pragma pack(push,_CRT_PACKING)


extern "C" {
# 49 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  typedef int (__attribute__((__cdecl__)) *_onexit_t)(void);
# 59 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  typedef struct _div_t {
    int quot;
    int rem;
  } div_t;

  typedef struct _ldiv_t {
    long quot;
    long rem;
  } ldiv_t;





#pragma pack(4)
  typedef struct {
    unsigned char ld[10];
  } _LDOUBLE;
#pragma pack()



  typedef struct {
    double x;
  } _CRT_DOUBLE;

  typedef struct {
    float f;
  } _CRT_FLOAT;

       


  typedef struct {
    long double x;
  } _LONGDOUBLE;

       

#pragma pack(4)
  typedef struct {
    unsigned char ld12[12];
  } _LDBL12;
#pragma pack()
# 114 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern int * __imp___mb_cur_max;
# 140 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  typedef void (__attribute__((__cdecl__)) *_purecall_handler)(void);

  __attribute__ ((__dllimport__)) _purecall_handler __attribute__((__cdecl__)) _set_purecall_handler(_purecall_handler _Handler);
  __attribute__ ((__dllimport__)) _purecall_handler __attribute__((__cdecl__)) _get_purecall_handler(void);

  typedef void (__attribute__((__cdecl__)) *_invalid_parameter_handler)(const wchar_t *,const wchar_t *,const wchar_t *,unsigned int,uintptr_t);
  __attribute__ ((__dllimport__)) _invalid_parameter_handler __attribute__((__cdecl__)) _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  __attribute__ ((__dllimport__)) _invalid_parameter_handler __attribute__((__cdecl__)) _get_invalid_parameter_handler(void);



  __attribute__ ((__dllimport__)) extern int *__attribute__((__cdecl__)) _errno(void);

  errno_t __attribute__((__cdecl__)) _set_errno(int _Value);
  errno_t __attribute__((__cdecl__)) _get_errno(int *_Value);

  __attribute__ ((__dllimport__)) unsigned long *__attribute__((__cdecl__)) __doserrno(void);

  errno_t __attribute__((__cdecl__)) _set_doserrno(unsigned long _Value);
  errno_t __attribute__((__cdecl__)) _get_doserrno(unsigned long *_Value);




  extern __attribute__((dllimport)) char *_sys_errlist[1];
  extern __attribute__((dllimport)) int _sys_nerr;
# 180 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern int * __imp___argc;







  extern char *** __imp___argv;







  extern wchar_t *** __imp___wargv;
# 208 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern char *** __imp__environ;
# 217 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern wchar_t *** __imp__wenviron;
# 226 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern char ** __imp__pgmptr;
# 235 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern wchar_t ** __imp__wpgmptr;



  errno_t __attribute__((__cdecl__)) _get_pgmptr(char **_Value);
  errno_t __attribute__((__cdecl__)) _get_wpgmptr(wchar_t **_Value);




  extern int * __imp__fmode;



  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _set_fmode(int _Mode);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _get_fmode(int *_PMode);





  extern unsigned int * __imp__osplatform;
# 265 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern unsigned int * __imp__osver;
# 274 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern unsigned int * __imp__winver;
# 283 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern unsigned int * __imp__winmajor;
# 292 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  extern unsigned int * __imp__winminor;




  errno_t __attribute__((__cdecl__)) _get_osplatform(unsigned int *_Value);
  errno_t __attribute__((__cdecl__)) _get_osver(unsigned int *_Value);
  errno_t __attribute__((__cdecl__)) _get_winver(unsigned int *_Value);
  errno_t __attribute__((__cdecl__)) _get_winmajor(unsigned int *_Value);
  errno_t __attribute__((__cdecl__)) _get_winminor(unsigned int *_Value);




  extern "C++" {
    template <typename _CountofType,size_t _SizeOfArray> char (*__countof_helper( _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

  }





  void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) exit(int _Code) __attribute__ ((__noreturn__));
  void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _exit(int _Code) __attribute__ ((__noreturn__));



  void __attribute__((__cdecl__)) _Exit(int) __attribute__ ((__noreturn__));






       

  void __attribute__((__cdecl__)) __attribute__((noreturn)) abort(void);
       



  __attribute__ ((__dllimport__)) unsigned int __attribute__((__cdecl__)) _set_abort_behavior(unsigned int _Flags,unsigned int _Mask);



  int __attribute__((__cdecl__)) abs(int _X);
  long __attribute__((__cdecl__)) labs(long _X);


  __extension__ long long __attribute__((__cdecl__)) _abs64(long long);

  extern __inline__ __attribute__((__always_inline__,__gnu_inline__)) long long __attribute__((__cdecl__)) _abs64(long long x) {
    return __builtin_llabs(x);
  }


  int __attribute__((__cdecl__)) atexit(void (__attribute__((__cdecl__)) *)(void));


  double __attribute__((__cdecl__)) atof(const char *_String);
  double __attribute__((__cdecl__)) _atof_l(const char *_String,_locale_t _Locale);

  int __attribute__((__cdecl__)) atoi(const char *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atoi_l(const char *_Str,_locale_t _Locale);
  long __attribute__((__cdecl__)) atol(const char *_Str);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _atol_l(const char *_Str,_locale_t _Locale);


  void *__attribute__((__cdecl__)) bsearch(const void *_Key,const void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (__attribute__((__cdecl__)) *_PtFuncCompare)(const void *,const void *));
  void __attribute__((__cdecl__)) qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (__attribute__((__cdecl__)) *_PtFuncCompare)(const void *,const void *));

  unsigned short __attribute__((__cdecl__)) _byteswap_ushort(unsigned short _Short);
  unsigned long __attribute__((__cdecl__)) _byteswap_ulong (unsigned long _Long);
  __extension__ unsigned long long __attribute__((__cdecl__)) _byteswap_uint64(unsigned long long _Int64);
  div_t __attribute__((__cdecl__)) div(int _Numerator,int _Denominator);
  char *__attribute__((__cdecl__)) getenv(const char *_VarName) ;
  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _itoa(int _Value,char *_Dest,int _Radix);
  __extension__ __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _i64toa(long long _Val,char *_DstBuf,int _Radix) ;
  __extension__ __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _ui64toa(unsigned long long _Val,char *_DstBuf,int _Radix) ;
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _atoi64(const char *_String);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _atoi64_l(const char *_String,_locale_t _Locale);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _strtoi64(const char *_String,char **_EndPtr,int _Radix);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _strtoi64_l(const char *_String,char **_EndPtr,int _Radix,_locale_t _Locale);
  __extension__ __attribute__ ((__dllimport__)) unsigned long long __attribute__((__cdecl__)) _strtoui64(const char *_String,char **_EndPtr,int _Radix);
  __extension__ __attribute__ ((__dllimport__)) unsigned long long __attribute__((__cdecl__)) _strtoui64_l(const char *_String,char **_EndPtr,int _Radix,_locale_t _Locale);
  ldiv_t __attribute__((__cdecl__)) ldiv(long _Numerator,long _Denominator);
  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _ltoa(long _Value,char *_Dest,int _Radix) ;
  int __attribute__((__cdecl__)) mblen(const char *_Ch,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _mblen_l(const char *_Ch,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _mbstrlen(const char *_Str);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _mbstrlen_l(const char *_Str,_locale_t _Locale);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _mbstrnlen(const char *_Str,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _mbstrnlen_l(const char *_Str,size_t _MaxCount,_locale_t _Locale);
  int __attribute__((__cdecl__)) mbtowc(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SrcSizeInBytes);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _mbtowc_l(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t __attribute__((__cdecl__)) mbstowcs(wchar_t * __restrict__ _Dest,const char * __restrict__ _Source,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _mbstowcs_l(wchar_t * __restrict__ _Dest,const char * __restrict__ _Source,size_t _MaxCount,_locale_t _Locale);
  int __attribute__((__cdecl__)) mkstemp(char *template_name);
  int __attribute__((__cdecl__)) rand(void);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _set_error_mode(int _Mode);
  void __attribute__((__cdecl__)) srand(unsigned int _Seed);
# 404 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
inline __attribute__((__cdecl__))
double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtod(const char * __restrict__ _Str,char ** __restrict__ _EndPtr)
{
  double __attribute__((__cdecl__)) __mingw_strtod (const char * __restrict__, char ** __restrict__);
  return __mingw_strtod( _Str, _EndPtr);
}

inline __attribute__((__cdecl__))
float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtof(const char * __restrict__ _Str,char ** __restrict__ _EndPtr)
{
  float __attribute__((__cdecl__)) __mingw_strtof (const char * __restrict__, char ** __restrict__);
  return __mingw_strtof( _Str, _EndPtr);
}






  long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtold(const char * __restrict__ , char ** __restrict__ );


  extern double __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
  __strtod (const char * __restrict__ , char ** __restrict__);






  float __attribute__((__cdecl__)) __mingw_strtof (const char * __restrict__, char ** __restrict__);
  double __attribute__((__cdecl__)) __mingw_strtod (const char * __restrict__, char ** __restrict__);
  long double __attribute__((__cdecl__)) __mingw_strtold(const char * __restrict__, char ** __restrict__);

  __attribute__ ((__dllimport__)) double __attribute__((__cdecl__)) _strtod_l(const char * __restrict__ _Str,char ** __restrict__ _EndPtr,_locale_t _Locale);
  long __attribute__((__cdecl__)) strtol(const char * __restrict__ _Str,char ** __restrict__ _EndPtr,int _Radix);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _strtol_l(const char * __restrict__ _Str,char ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  unsigned long __attribute__((__cdecl__)) strtoul(const char * __restrict__ _Str,char ** __restrict__ _EndPtr,int _Radix);
  __attribute__ ((__dllimport__)) unsigned long __attribute__((__cdecl__)) _strtoul_l(const char * __restrict__ _Str,char ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);


  int __attribute__((__cdecl__)) system(const char *_Command);

  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _ultoa(unsigned long _Value,char *_Dest,int _Radix) ;
  int __attribute__((__cdecl__)) wctomb(char *_MbCh,wchar_t _WCh) ;
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wctomb_l(char *_MbCh,wchar_t _WCh,_locale_t _Locale) ;
  size_t __attribute__((__cdecl__)) wcstombs(char * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _wcstombs_l(char * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _MaxCount,_locale_t _Locale) ;



  void *__attribute__((__cdecl__)) calloc(size_t _NumOfElements,size_t _SizeOfElements);
  void __attribute__((__cdecl__)) free(void *_Memory);
  void *__attribute__((__cdecl__)) malloc(size_t _Size);
  void *__attribute__((__cdecl__)) realloc(void *_Memory,size_t _NewSize);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _recalloc(void *_Memory,size_t _Count,size_t _Size);


       
       


  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _aligned_free(void *_Memory);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_malloc(size_t _Size,size_t _Alignment);
       
       

  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_realloc(void *_Memory,size_t _Size,size_t _Alignment);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_offset_realloc(void *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _aligned_offset_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);





  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _itow(int _Value,wchar_t *_Dest,int _Radix) ;
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _ltow(long _Value,wchar_t *_Dest,int _Radix) ;
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _ultow(unsigned long _Value,wchar_t *_Dest,int _Radix) ;

  double __attribute__((__cdecl__)) __mingw_wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr);
  float __attribute__((__cdecl__)) __mingw_wcstof(const wchar_t * __restrict__ nptr, wchar_t ** __restrict__ endptr);
  long double __attribute__((__cdecl__)) __mingw_wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);


  inline __attribute__((__cdecl__))
  double __attribute__((__cdecl__)) wcstod(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstod(_Str,_EndPtr);
  }
  inline __attribute__((__cdecl__))
  float __attribute__((__cdecl__)) wcstof(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr){
    return __mingw_wcstof(_Str,_EndPtr);
  }






  long double __attribute__((__cdecl__)) wcstold(const wchar_t * __restrict__, wchar_t ** __restrict__);

  __attribute__ ((__dllimport__)) double __attribute__((__cdecl__)) _wcstod_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,_locale_t _Locale);
  long __attribute__((__cdecl__)) wcstol(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _wcstol_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  unsigned long __attribute__((__cdecl__)) wcstoul(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix);
  __attribute__ ((__dllimport__)) unsigned long __attribute__((__cdecl__)) _wcstoul_l(const wchar_t * __restrict__ _Str,wchar_t ** __restrict__ _EndPtr,int _Radix,_locale_t _Locale);
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _wgetenv(const wchar_t *_VarName) ;


  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wsystem(const wchar_t *_Command);

  __attribute__ ((__dllimport__)) double __attribute__((__cdecl__)) _wtof(const wchar_t *_Str);
  __attribute__ ((__dllimport__)) double __attribute__((__cdecl__)) _wtof_l(const wchar_t *_Str,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wtoi(const wchar_t *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wtoi_l(const wchar_t *_Str,_locale_t _Locale);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _wtol(const wchar_t *_Str);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _wtol_l(const wchar_t *_Str,_locale_t _Locale);

  __extension__ __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _i64tow(long long _Val,wchar_t *_DstBuf,int _Radix) ;
  __extension__ __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _ui64tow(unsigned long long _Val,wchar_t *_DstBuf,int _Radix) ;
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _wtoi64(const wchar_t *_Str);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _wtoi64_l(const wchar_t *_Str,_locale_t _Locale);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _wcstoi64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _wcstoi64_l(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);
  __extension__ __attribute__ ((__dllimport__)) unsigned long long __attribute__((__cdecl__)) _wcstoui64(const wchar_t *_Str,wchar_t **_EndPtr,int _Radix);
  __extension__ __attribute__ ((__dllimport__)) unsigned long long __attribute__((__cdecl__)) _wcstoui64_l(const wchar_t *_Str ,wchar_t **_EndPtr,int _Radix,_locale_t _Locale);


  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _putenv(const char *_EnvString);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wputenv(const wchar_t *_EnvString);



  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _fullpath(char *_FullPath,const char *_Path,size_t _SizeInBytes);
  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _ecvt(double _Val,int _NumOfDigits,int *_PtDec,int *_PtSign) ;
  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _fcvt(double _Val,int _NumOfDec,int *_PtDec,int *_PtSign) ;
  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _gcvt(double _Val,int _NumOfDigits,char *_DstBuf) ;
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atodbl(_CRT_DOUBLE *_Result,char *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atoldbl(_LDOUBLE *_Result,char *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atoflt(_CRT_FLOAT *_Result,char *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atodbl_l(_CRT_DOUBLE *_Result,char *_Str,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atoldbl_l(_LDOUBLE *_Result,char *_Str,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _atoflt_l(_CRT_FLOAT *_Result,char *_Str,_locale_t _Locale);
# 563 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
unsigned long __attribute__((__cdecl__)) _lrotl(unsigned long,int);
unsigned long __attribute__((__cdecl__)) _lrotr(unsigned long,int);





  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _makepath(char *_Path,const char *_Drive,const char *_Dir,const char *_Filename,const char *_Ext);
  _onexit_t __attribute__((__cdecl__)) _onexit(_onexit_t _Func);



  void __attribute__((__cdecl__)) perror(const char *_ErrMsg);

       
       


  __extension__ unsigned long long __attribute__((__cdecl__)) _rotl64(unsigned long long _Val,int _Shift);
  __extension__ unsigned long long __attribute__((__cdecl__)) _rotr64(unsigned long long Value,int Shift);
       
       
       
       


  unsigned int __attribute__((__cdecl__)) _rotr(unsigned int _Val,int _Shift);
  unsigned int __attribute__((__cdecl__)) _rotl(unsigned int _Val,int _Shift);
       
       
  __extension__ unsigned long long __attribute__((__cdecl__)) _rotr64(unsigned long long _Val,int _Shift);
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _searchenv(const char *_Filename,const char *_EnvVar,char *_ResultPath) ;
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _splitpath(const char *_FullPath,char *_Drive,char *_Dir,char *_Filename,char *_Ext) ;
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _swab(char *_Buf1,char *_Buf2,int _SizeInBytes);



  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _wfullpath(wchar_t *_FullPath,const wchar_t *_Path,size_t _SizeInWords);
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _wmakepath(wchar_t *_ResultPath,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);


  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _wperror(const wchar_t *_ErrMsg);

  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _wsearchenv(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath) ;
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _wsplitpath(const wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext) ;


  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _beep(unsigned _Frequency,unsigned _Duration) __attribute__ ((__deprecated__));

  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _seterrormode(int _Mode) __attribute__ ((__deprecated__));
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _sleep(unsigned long _Duration) __attribute__ ((__deprecated__));
# 634 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
  char *__attribute__((__cdecl__)) ecvt(double _Val,int _NumOfDigits,int *_PtDec,int *_PtSign) ;
  char *__attribute__((__cdecl__)) fcvt(double _Val,int _NumOfDec,int *_PtDec,int *_PtSign) ;
  char *__attribute__((__cdecl__)) gcvt(double _Val,int _NumOfDigits,char *_DstBuf) ;
  char *__attribute__((__cdecl__)) itoa(int _Val,char *_DstBuf,int _Radix) ;
  char *__attribute__((__cdecl__)) ltoa(long _Val,char *_DstBuf,int _Radix) ;
  int __attribute__((__cdecl__)) putenv(const char *_EnvString) ;



  void __attribute__((__cdecl__)) swab(char *_Buf1,char *_Buf2,int _SizeInBytes) ;


  char *__attribute__((__cdecl__)) ultoa(unsigned long _Val,char *_Dstbuf,int _Radix) ;
  _onexit_t __attribute__((__cdecl__)) onexit(_onexit_t _Func);





  typedef struct { __extension__ long long quot, rem; } lldiv_t;

  __extension__ lldiv_t __attribute__((__cdecl__)) lldiv(long long, long long);

  __extension__ long long __attribute__((__cdecl__)) llabs(long long);




  __extension__ long long __attribute__((__cdecl__)) strtoll(const char * __restrict__, char ** __restrict, int);
  __extension__ unsigned long long __attribute__((__cdecl__)) strtoull(const char * __restrict__, char ** __restrict__, int);


  __extension__ long long __attribute__((__cdecl__)) atoll (const char *);


  __extension__ long long __attribute__((__cdecl__)) wtoll (const wchar_t *);
  __extension__ char *__attribute__((__cdecl__)) lltoa (long long, char *, int);
  __extension__ char *__attribute__((__cdecl__)) ulltoa (unsigned long long , char *, int);
  __extension__ wchar_t *__attribute__((__cdecl__)) lltow (long long, wchar_t *, int);
  __extension__ wchar_t *__attribute__((__cdecl__)) ulltow (unsigned long long, wchar_t *, int);
# 689 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 3
}


#pragma pack(pop)

# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdlib_s.h" 1 3
# 9 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdlib_s.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 1 3
# 30 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 1 3
# 31 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 2 3
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdlib_s.h" 2 3




extern "C" {


  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _dupenv_s(char **_PBuffer,size_t *_PBufferSizeInBytes,const char *_VarName);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _itoa_s(int _Value,char *_DstBuf,size_t _Size,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _i64toa_s(long long _Val,char *_DstBuf,size_t _Size,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ui64toa_s(unsigned long long _Val,char *_DstBuf,size_t _Size,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ltoa_s(long _Val,char *_DstBuf,size_t _Size,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) mbstowcs_s(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,const char *_SrcBuf,size_t _MaxCount);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,const char *_SrcBuf,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ultoa_s(unsigned long _Val,char *_DstBuf,size_t _Size,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) wcstombs_s(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t _MaxCountInBytes);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wcstombs_s_l(size_t *_PtNumOfCharConverted,char *_Dst,size_t _DstSizeInBytes,const wchar_t *_Src,size_t _MaxCountInBytes,_locale_t _Locale);



  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _itow_s (int _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ltow_s (long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ultow_s (unsigned long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,const wchar_t *_VarName);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,const wchar_t *_VarName);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _i64tow_s(long long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ui64tow_s(unsigned long long _Val,wchar_t *_DstBuf,size_t _SizeInWords,int _Radix);



  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _ecvt_s(char *_DstBuf,size_t _Size,double _Val,int _NumOfDights,int *_PtDec,int *_PtSign);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _fcvt_s(char *_DstBuf,size_t _Size,double _Val,int _NumOfDec,int *_PtDec,int *_PtSign);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _gcvt_s(char *_DstBuf,size_t _Size,double _Val,int _NumOfDigits);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _makepath_s(char *_PathResult,size_t _Size,const char *_Drive,const char *_Dir,const char *_Filename,const char *_Ext);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _putenv_s(const char *_Name,const char *_Value);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _searchenv_s(const char *_Filename,const char *_EnvVar,char *_ResultPath,size_t _SizeInBytes);

  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _splitpath_s(const char *_FullPath,char *_Drive,size_t _DriveSize,char *_Dir,size_t _DirSize,char *_Filename,size_t _FilenameSize,char *_Ext,size_t _ExtSize);
  extern "C++" { template <size_t __drive_size, size_t __dir_size, size_t __name_size, size_t __ext_size> inline errno_t __attribute__((__cdecl__)) _splitpath_s(const char *_Dest, char (&__drive)[__drive_size], char (&__dir)[__dir_size], char (&__name)[__name_size], char (&__ext)[__ext_size]) { return _splitpath_s(_Dest, __drive, __drive_size, __dir, __dir_size, __name, __name_size, __ext, __ext_size); } }



  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,const wchar_t *_Drive,const wchar_t *_Dir,const wchar_t *_Filename,const wchar_t *_Ext);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wputenv_s(const wchar_t *_Name,const wchar_t *_Value);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wsearchenv_s(const wchar_t *_Filename,const wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);

  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wsplitpath_s(const wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
  extern "C++" { template <size_t __drive_size, size_t __dir_size, size_t __name_size, size_t __ext_size> inline errno_t __attribute__((__cdecl__)) _wsplitpath_s(const wchar_t *_Dest, wchar_t (&__drive)[__drive_size], wchar_t (&__dir)[__dir_size], wchar_t (&__name)[__name_size], wchar_t (&__ext)[__ext_size]) { return _wsplitpath_s(_Dest, __drive, __drive_size, __dir, __dir_size, __name, __name_size, __ext, __ext_size); } }





  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) qsort_s(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (__attribute__((__cdecl__)) *_PtFuncCompare)(void *,const void *,const void *),void *_Context);





}
# 695 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 2 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 1 3
# 11 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
#pragma pack(push,_CRT_PACKING)


extern "C" {
# 46 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
  typedef struct _heapinfo {
    int *_pentry;
    size_t _size;
    int _useflag;
  } _HEAPINFO;


  extern unsigned int _amblksiz;
# 65 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
       
       
# 97 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
       
       




void * __mingw_aligned_malloc (size_t _Size, size_t _Alignment);
void __mingw_aligned_free (void *_Memory);
void * __mingw_aligned_offset_realloc (void *_Memory, size_t _Size, size_t _Alignment, size_t _Offset);
void * __mingw_aligned_realloc (void *_Memory, size_t _Size, size_t _Offset);



  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _resetstkoflw (void);
  __attribute__ ((__dllimport__)) unsigned long __attribute__((__cdecl__)) _set_malloc_crt_max_wait(unsigned long _NewValue);

  __attribute__ ((__dllimport__)) void *__attribute__((__cdecl__)) _expand(void *_Memory,size_t _NewSize);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _msize(void *_Memory);






  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _get_sbh_threshold(void);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _set_sbh_threshold(size_t _NewValue);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _set_amblksiz(size_t _Value);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _get_amblksiz(size_t *_Value);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _heapadd(void *_Memory,size_t _Size);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _heapchk(void);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _heapmin(void);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _heapset(unsigned int _Fill);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _heapwalk(_HEAPINFO *_EntryInfo);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _heapused(size_t *_Used,size_t *_Commit);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _get_heap_handle(void);
# 144 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
  static __inline void *_MarkAllocaS(void *_Ptr,unsigned int _Marker) {
    if(_Ptr) {
      *((unsigned int*)_Ptr) = _Marker;
      _Ptr = (char*)_Ptr + 16;
    }
    return _Ptr;
  }
# 163 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
  static __inline void __attribute__((__cdecl__)) _freea(void *_Memory) {
    unsigned int _Marker;
    if(_Memory) {
      _Memory = (char*)_Memory - 16;
      _Marker = *(unsigned int *)_Memory;
      if(_Marker==0xDDDD) {
 free(_Memory);
      }





    }
  }
# 206 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/malloc.h" 3
}


#pragma pack(pop)
# 696 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdlib.h" 2 3
# 76 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 2 3
# 118 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3
extern "C++"
{
namespace std
{


  using ::div_t;
  using ::ldiv_t;

  using ::abort;
  using ::abs;
  using ::atexit;





  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;

  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;

  using ::qsort;





  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;

  using ::wcstombs;
  using ::wctomb;



  inline long
  abs(long __i) { return __builtin_labs(__i); }

  inline ldiv_t
  div(long __i, long __j) { return ldiv(__i, __j); }



  inline long long
  abs(long long __x) { return __builtin_llabs (__x); }



  inline __int128
  abs(__int128 __x) { return __x >= 0 ? __x : -__x; }
# 201 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3

}
# 215 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3
namespace __gnu_cxx
{



  using ::lldiv_t;





  using ::_Exit;



  using ::llabs;

  inline lldiv_t
  div(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  using ::lldiv;
# 247 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/cstdlib" 3
  using ::atoll;
  using ::strtoll;
  using ::strtoull;

  using ::strtof;
  using ::strtold;


}

namespace std
{

  using ::__gnu_cxx::lldiv_t;

  using ::__gnu_cxx::_Exit;

  using ::__gnu_cxx::llabs;
  using ::__gnu_cxx::div;
  using ::__gnu_cxx::lldiv;

  using ::__gnu_cxx::atoll;
  using ::__gnu_cxx::strtof;
  using ::__gnu_cxx::strtoll;
  using ::__gnu_cxx::strtoull;
  using ::__gnu_cxx::strtold;
}



}
# 37 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 2 3

using std::abort;
using std::atexit;
using std::exit;
# 51 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 3
using std::div_t;
using std::ldiv_t;

using std::abs;
using std::atof;
using std::atoi;
using std::atol;
using std::bsearch;
using std::calloc;
using std::div;
using std::free;
using std::getenv;
using std::labs;
using std::ldiv;
using std::malloc;

using std::mblen;
using std::mbstowcs;
using std::mbtowc;

using std::qsort;
using std::rand;
using std::realloc;
using std::srand;
using std::strtod;
using std::strtol;
using std::strtoul;
using std::system;

using std::wcstombs;
using std::wctomb;
# 18 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/assert.h" 2 3



extern "C" {
# 45 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/assert.h" 3
extern void __attribute__((__cdecl__))
_wassert(const wchar_t *_Message,const wchar_t *_File,unsigned _Line);
extern void __attribute__((__cdecl__))
_assert (const char *_Message, const char *_File, unsigned _Line);


}
# 35 "G:/Repo/hls_project/src/BWT.h" 2
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stdint.h" 1 3 4
# 9 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stdint.h" 3 4
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 1 3 4
# 32 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 3 4
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stddef.h" 1 3 4
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 1 3 4
# 13 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
extern "C" {
# 24 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stddef.h" 3 4
  __attribute__ ((__dllimport__)) extern unsigned long __attribute__((__cdecl__)) __threadid(void);

  __attribute__ ((__dllimport__)) extern uintptr_t __attribute__((__cdecl__)) __threadhandle(void);


}
# 2 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stddef.h" 2 3 4
# 427 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;






  typedef decltype(nullptr) nullptr_t;
# 33 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdint.h" 2 3 4


typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
__extension__ typedef long long int64_t;
__extension__ typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
__extension__ typedef long long int_least64_t;
__extension__ typedef unsigned long long uint_least64_t;





typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
__extension__ typedef long long int_fast64_t;
__extension__ typedef unsigned long long uint_fast64_t;


__extension__ typedef long long intmax_t;
__extension__ typedef unsigned long long uintmax_t;
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/lib/gcc/x86_64-w64-mingw32/6.2.0/include/stdint.h" 2 3 4
# 36 "G:/Repo/hls_project/src/BWT.h" 2
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 1 3
# 11 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_print_push.h" 1 3
# 12 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 2 3

#pragma pack(push,_CRT_PACKING)


extern "C" {
# 26 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
# 80 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_off_t.h" 1 3




  typedef long _off_t;

  typedef long off32_t;





  __extension__ typedef long long _off64_t;

  __extension__ typedef long long off64_t;
# 26 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_off_t.h" 3
typedef off32_t off_t;
# 81 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 2 3



  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) __iob_func(void);
# 103 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __extension__ typedef long long fpos_t;
# 139 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
extern
  __attribute__((__format__ (gnu_scanf, 2, 3))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...);
extern
  __attribute__((__format__ (gnu_scanf, 2, 0))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vsscanf (const char * __restrict__ _Str,const char * __restrict__ Format,va_list argp);
extern
  __attribute__((__format__ (gnu_scanf, 1, 2))) __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_scanf(const char * __restrict__ _Format,...);
extern
  __attribute__((__format__ (gnu_scanf, 1, 0))) __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_vscanf(const char * __restrict__ Format, va_list argp);
extern
  __attribute__((__format__ (gnu_scanf, 2, 3))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
extern
  __attribute__((__format__ (gnu_scanf, 2, 0))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vfscanf (FILE * __restrict__ fp, const char * __restrict__ Format,va_list argp);

extern
  __attribute__((__format__ (gnu_printf, 3, 0))) __attribute__ ((__nonnull__ (3)))
  int __attribute__((__cdecl__)) __mingw_vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restrict__ _Format,
                               va_list _ArgList);
extern
  __attribute__((__format__ (gnu_printf, 3, 4))) __attribute__ ((__nonnull__ (3)))
  int __attribute__((__cdecl__)) __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__ format, ...);
extern
  __attribute__((__format__ (gnu_printf, 1, 2))) __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_printf(const char * __restrict__ , ... ) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 1, 0))) __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_vprintf (const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_fprintf (FILE * __restrict__ , const char * __restrict__ , ...) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_sprintf (char * __restrict__ , const char * __restrict__ , ...) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vsprintf (char * __restrict__ , const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__((nonnull (1,2)))
  int __attribute__((__cdecl__)) __mingw_asprintf(char ** __restrict__ , const char * __restrict__ , ...) __attribute__ ((__nothrow__));
extern
  __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__((nonnull (1,2)))
  int __attribute__((__cdecl__)) __mingw_vasprintf(char ** __restrict__ , const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
# 222 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
extern "C++" {


inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 2, 3))) __attribute__ ((__nonnull__ (2)))
int sscanf(const char *__source, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsscanf( __source, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 1, 2))) __attribute__ ((__nonnull__ (1)))
int scanf(const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vscanf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 2, 3))) __attribute__ ((__nonnull__ (2)))
int fscanf(FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfscanf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"


inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 2, 0))) __attribute__ ((__nonnull__ (2)))
int vsscanf (const char *__source, const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vsscanf( __source, __format, __local_argv );
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 1, 0))) __attribute__ ((__nonnull__ (1)))
int vscanf(const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vscanf( __format, __local_argv );
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_scanf, 2, 0))) __attribute__ ((__nonnull__ (2)))
int vfscanf (FILE *__stream, const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vfscanf( __stream, __format, __local_argv );
}


#pragma GCC diagnostic pop





inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
int fprintf (FILE *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 1, 2))) __attribute__ ((__nonnull__ (1)))
int printf (const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
int sprintf (char *__stream, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
int vfprintf (FILE *__stream, const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vfprintf( __stream, __format, __local_argv );
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 1, 0))) __attribute__ ((__nonnull__ (1)))
int vprintf (const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vprintf( __format, __local_argv );
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
int vsprintf (char *__stream, const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vsprintf( __stream, __format, __local_argv );
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 3, 4))) __attribute__ ((__nonnull__ (3)))
int snprintf (char *__stream, size_t __n, const char *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsnprintf( __stream, __n, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
__attribute__((__format__ (gnu_printf, 3, 0))) __attribute__ ((__nonnull__ (3)))
int vsnprintf (char *__stream, size_t __n, const char *__format, __builtin_va_list __local_argv)
{
  return __mingw_vsnprintf( __stream, __n, __format, __local_argv );
}
# 371 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
}
# 450 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _filbuf(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _flsbuf(int _Ch,FILE *_File);



  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _fsopen(const char *_Filename,const char *_Mode,int _ShFlag);

  void __attribute__((__cdecl__)) clearerr(FILE *_File);
  int __attribute__((__cdecl__)) fclose(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fcloseall(void);



  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _fdopen(int _FileHandle,const char *_Mode);

  int __attribute__((__cdecl__)) feof(FILE *_File);
  int __attribute__((__cdecl__)) ferror(FILE *_File);
  int __attribute__((__cdecl__)) fflush(FILE *_File);
  int __attribute__((__cdecl__)) fgetc(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fgetchar(void);
  int __attribute__((__cdecl__)) fgetpos(FILE * __restrict__ _File ,fpos_t * __restrict__ _Pos);
  int __attribute__((__cdecl__)) fgetpos64(FILE * __restrict__ _File ,fpos_t * __restrict__ _Pos);
  char *__attribute__((__cdecl__)) fgets(char * __restrict__ _Buf,int _MaxCount,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fileno(FILE *_File);



  __attribute__ ((__dllimport__)) char *__attribute__((__cdecl__)) _tempnam(const char *_DirName,const char *_FilePrefix);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _flushall(void);
  FILE *__attribute__((__cdecl__)) fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) ;
  FILE *fopen64(const char * __restrict__ filename,const char * __restrict__ mode);
  int __attribute__((__cdecl__)) fputc(int _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fputchar(int _Ch);
  int __attribute__((__cdecl__)) fputs(const char * __restrict__ _Str,FILE * __restrict__ _File);
  size_t __attribute__((__cdecl__)) fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  FILE *__attribute__((__cdecl__)) freopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode,FILE * __restrict__ _File) ;
  int __attribute__((__cdecl__)) fsetpos(FILE *_File,const fpos_t *_Pos);
  int __attribute__((__cdecl__)) fsetpos64(FILE *_File,const fpos_t *_Pos);
  int __attribute__((__cdecl__)) fseek(FILE *_File,long _Offset,int _Origin);



  int fseeko64(FILE* stream, _off64_t offset, int whence);
  int fseeko(FILE* stream, _off_t offset, int whence);
# 502 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  long __attribute__((__cdecl__)) ftell(FILE *_File);

  _off_t ftello(FILE * stream);
  _off64_t ftello64(FILE * stream);
# 514 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __extension__ int __attribute__((__cdecl__)) _fseeki64(FILE *_File,long long _Offset,int _Origin);
  __extension__ long long __attribute__((__cdecl__)) _ftelli64(FILE *_File);
  size_t __attribute__((__cdecl__)) fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  int __attribute__((__cdecl__)) getc(FILE *_File);
  int __attribute__((__cdecl__)) getchar(void);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _getmaxstdio(void);
  char *__attribute__((__cdecl__)) gets(char *_Buffer) ;
  int __attribute__((__cdecl__)) _getw(FILE *_File);




  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _pclose(FILE *_File);
  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _popen(const char *_Command,const char *_Mode);




  int __attribute__((__cdecl__)) putc(int _Ch,FILE *_File);
  int __attribute__((__cdecl__)) putchar(int _Ch);
  int __attribute__((__cdecl__)) puts(const char *_Str);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _putw(int _Word,FILE *_File);


  int __attribute__((__cdecl__)) remove(const char *_Filename);
  int __attribute__((__cdecl__)) rename(const char *_OldFilename,const char *_NewFilename);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _unlink(const char *_Filename);

  int __attribute__((__cdecl__)) unlink(const char *_Filename) ;


  void __attribute__((__cdecl__)) rewind(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _rmtmp(void);
  void __attribute__((__cdecl__)) setbuf(FILE * __restrict__ _File,char * __restrict__ _Buffer) ;
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _setmaxstdio(int _Max);
  __attribute__ ((__dllimport__)) unsigned int __attribute__((__cdecl__)) _set_output_format(unsigned int _Format);
  __attribute__ ((__dllimport__)) unsigned int __attribute__((__cdecl__)) _get_output_format(void);
  int __attribute__((__cdecl__)) setvbuf(FILE * __restrict__ _File,char * __restrict__ _Buf,int _Mode,size_t _Size);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scprintf(const char * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snscanf(const char * __restrict__ _Src,size_t _MaxCount,const char * __restrict__ _Format,...) ;
  FILE *__attribute__((__cdecl__)) tmpfile(void) ;
  char *__attribute__((__cdecl__)) tmpnam(char *_Buffer);
  int __attribute__((__cdecl__)) ungetc(int _Ch,FILE *_File);

  __attribute__((__format__ (ms_printf, 3, 4))) __attribute__ ((__nonnull__ (3)))
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,...) ;
  __attribute__((__format__ (ms_printf, 3, 0))) __attribute__ ((__nonnull__ (3)))
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,va_list _Args) ;
# 610 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscprintf(const char * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _set_printf_count_output(int _Value);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _get_printf_count_output(void);




                                                     __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...);
                                                     __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vswscanf (const wchar_t * __restrict__ _Str,const wchar_t * __restrict__ Format,va_list argp);
                                                     __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_wscanf(const wchar_t * __restrict__ _Format,...);
                                                     __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_vwscanf(const wchar_t * __restrict__ Format, va_list argp);
                                                     __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
                                                     __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vfwscanf (FILE * __restrict__ fp, const wchar_t * __restrict__ Format,va_list argp);

                                                      __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
                                                      __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_wprintf(const wchar_t * __restrict__ _Format,...);
                                                     __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
                                                     __attribute__ ((__nonnull__ (1)))
  int __attribute__((__cdecl__)) __mingw_vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
                                                      __attribute__ ((__nonnull__ (3)))
  int __attribute__((__cdecl__)) __mingw_snwprintf (wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
                                                      __attribute__ ((__nonnull__ (3)))
  int __attribute__((__cdecl__)) __mingw_vsnwprintf (wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , va_list);
                                                      __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_swprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ , ...);
                                                      __attribute__ ((__nonnull__ (2)))
  int __attribute__((__cdecl__)) __mingw_vswprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ ,va_list);






inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (2)))
int swscanf(const wchar_t *__source, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vswscanf( __source, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (1)))
int wscanf(const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vwscanf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (2)))
int fwscanf(FILE *__stream, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfwscanf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}


inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (2)))
int vswscanf (const wchar_t * __restrict__ __source, const wchar_t * __restrict__ __format, __builtin_va_list __local_argv)
{
  return __mingw_vswscanf( __source, __format, __local_argv );
}

inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (1)))
int vwscanf(const wchar_t *__format, __builtin_va_list __local_argv)
{
  return __mingw_vwscanf( __format, __local_argv );
}

inline __attribute__((__cdecl__))
                                                     __attribute__ ((__nonnull__ (2)))
int vfwscanf (FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
{
  return __mingw_vfwscanf( __stream, __format, __local_argv );
}




inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (2)))
int fwprintf (FILE *__stream, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vfwprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (1)))
int wprintf (const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vwprintf( __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (2)))
int vfwprintf (FILE *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
{
  return __mingw_vfwprintf( __stream, __format, __local_argv );
}

inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (1)))
int vwprintf (const wchar_t *__format, __builtin_va_list __local_argv)
{
  return __mingw_vwprintf( __format, __local_argv );
}


inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (3)))
int snwprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
  __retval = __mingw_vsnwprintf( __stream, __n, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

inline __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (3)))
int vsnwprintf (wchar_t *__stream, size_t __n, const wchar_t *__format, __builtin_va_list __local_argv)
{
  return __mingw_vsnwprintf( __stream, __n, __format, __local_argv );
}
# 811 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,int _ShFlag);


  wint_t __attribute__((__cdecl__)) fgetwc(FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __attribute__((__cdecl__)) _fgetwchar(void);
  wint_t __attribute__((__cdecl__)) fputwc(wchar_t _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __attribute__((__cdecl__)) _fputwchar(wchar_t _Ch);
  wint_t __attribute__((__cdecl__)) getwc(FILE *_File);
  wint_t __attribute__((__cdecl__)) getwchar(void);
  wint_t __attribute__((__cdecl__)) putwc(wchar_t _Ch,FILE *_File);
  wint_t __attribute__((__cdecl__)) putwchar(wchar_t _Ch);
  wint_t __attribute__((__cdecl__)) ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__attribute__((__cdecl__)) fgetws(wchar_t * __restrict__ _Dst,int _SizeInWords,FILE * __restrict__ _File);
  int __attribute__((__cdecl__)) fputws(const wchar_t * __restrict__ _Str,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _getws(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _putws(const wchar_t *_Str);

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scwprintf(const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vswprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args) ;
# 863 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vswprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,va_list _Args);


# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/swprintf.inl" 1 3
# 21 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/swprintf.inl" 3
static __attribute__ ((__unused__)) __inline__ __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (3)))
int vswprintf (wchar_t *__stream, size_t __count, const wchar_t *__format, __builtin_va_list __local_argv)
{
  return vsnwprintf( __stream, __count, __format, __local_argv );
}

static __attribute__ ((__unused__)) __inline__ __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (3)))
int swprintf (wchar_t *__stream, size_t __count, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv;

  __builtin_va_start( __local_argv, __format );
  __retval = vswprintf( __stream, __count, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}



extern "C++" {

static __attribute__ ((__unused__)) __inline__ __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (2)))
int vswprintf (wchar_t *__stream, const wchar_t *__format, __builtin_va_list __local_argv)
{

  return __mingw_vswprintf( __stream, __format, __local_argv );



}

static __attribute__ ((__unused__)) __inline__ __attribute__((__cdecl__))
                                                      __attribute__ ((__nonnull__ (2)))
int swprintf (wchar_t *__stream, const wchar_t *__format, ...)
{
  register int __retval;
  __builtin_va_list __local_argv;

  __builtin_va_start( __local_argv, __format );
  __retval = vswprintf( __stream, __format, __local_argv );
  __builtin_va_end( __local_argv );
  return __retval;
}

}
# 868 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 2 3
# 877 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _wtempnam(const wchar_t *_Directory,const wchar_t *_FilePrefix);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwscanf(const wchar_t * __restrict__ _Src,size_t _MaxCount,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _wfdopen(int _FileHandle ,const wchar_t *_Mode);
  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _wfopen(const wchar_t * __restrict__ _Filename,const wchar_t *__restrict__ _Mode) ;
  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _wfreopen(const wchar_t * __restrict__ _Filename,const wchar_t * __restrict__ _Mode,FILE * __restrict__ _OldFile) ;





  __attribute__ ((__dllimport__)) FILE *__attribute__((__cdecl__)) _wpopen(const wchar_t *_Command,const wchar_t *_Mode);




  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wremove(const wchar_t *_Filename);
  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _wtmpnam(wchar_t *_Buffer);
  __attribute__ ((__dllimport__)) wint_t __attribute__((__cdecl__)) _fgetwc_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __attribute__((__cdecl__)) _fputwc_nolock(wchar_t _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __attribute__((__cdecl__)) _ungetwc_nolock(wint_t _Ch,FILE *_File);
# 927 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _lock_file(FILE *_File);
  __attribute__ ((__dllimport__)) void __attribute__((__cdecl__)) _unlock_file(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fclose_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fflush_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _fread_nolock(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fseek_nolock(FILE *_File,long _Offset,int _Origin);
  __attribute__ ((__dllimport__)) long __attribute__((__cdecl__)) _ftell_nolock(FILE *_File);
  __extension__ __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fseeki64_nolock(FILE *_File,long long _Offset,int _Origin);
  __extension__ __attribute__ ((__dllimport__)) long long __attribute__((__cdecl__)) _ftelli64_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _fwrite_nolock(const void * __restrict__ _DstBuf,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _ungetc_nolock(int _Ch,FILE *_File);





  char *__attribute__((__cdecl__)) tempnam(const char *_Directory,const char *_FilePrefix) ;
  int __attribute__((__cdecl__)) fcloseall(void) ;
  FILE *__attribute__((__cdecl__)) fdopen(int _FileHandle,const char *_Format) ;
  int __attribute__((__cdecl__)) fgetchar(void) ;
  int __attribute__((__cdecl__)) fileno(FILE *_File) ;
  int __attribute__((__cdecl__)) flushall(void) ;
  int __attribute__((__cdecl__)) fputchar(int _Ch) ;
  int __attribute__((__cdecl__)) getw(FILE *_File) ;
  int __attribute__((__cdecl__)) putw(int _Ch,FILE *_File) ;
  int __attribute__((__cdecl__)) rmtmp(void) ;
# 969 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
int __attribute__((__cdecl__)) __mingw_str_wide_utf8 (const wchar_t * const wptr, char **mbptr, size_t * buflen);
# 983 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
int __attribute__((__cdecl__)) __mingw_str_utf8_wide (const char *const mbptr, wchar_t ** wptr, size_t * buflen);
# 992 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
void __attribute__((__cdecl__)) __mingw_str_free(void *ptr);





  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnl(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnle(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnlp(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnlpe(int _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnv(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnve(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnvp(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _wspawnvpe(int _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
# 1022 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 3
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _spawnv(int _Mode,const char *_Filename,const char *const *_ArgList);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _spawnve(int _Mode,const char *_Filename,const char *const *_ArgList,const char *const *_Env);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _spawnvp(int _Mode,const char *_Filename,const char *const *_ArgList);
  __attribute__ ((__dllimport__)) intptr_t __attribute__((__cdecl__)) _spawnvpe(int _Mode,const char *_Filename,const char *const *_ArgList,const char *const *_Env);



}


#pragma pack(pop)

# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdio_s.h" 1 3
# 9 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdio_s.h" 3
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 1 3
# 10 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdio_s.h" 2 3
# 23 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/sec_api/stdio_s.h" 3
extern "C" {




  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) clearerr_s(FILE *_File);
  int __attribute__((__cdecl__)) fprintf_s(FILE *_File,const char *_Format,...);
  size_t __attribute__((__cdecl__)) fread_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fscanf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  int __attribute__((__cdecl__)) printf_s(const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scanf_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scanf_s_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf_c(char *_DstBuf,size_t _MaxCount,const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf_c(char *_DstBuf,size_t _MaxCount,const char *_Format,va_list _ArgList);

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fscanf_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sscanf_l(const char *_Src,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sscanf_s_l(const char *_Src,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) sscanf_s(const char *_Src,const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snscanf_s(const char *_Src,size_t _MaxCount,const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snscanf_l(const char *_Src,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snscanf_s_l(const char *_Src,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  int __attribute__((__cdecl__)) vfprintf_s(FILE *_File,const char *_Format,va_list _ArgList);
  int __attribute__((__cdecl__)) vprintf_s(const char *_Format,va_list _ArgList);

  int __attribute__((__cdecl__)) vsnprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,va_list _ArgList);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) vsnprintf_s(char (&_DstBuf)[__size], size_t _MaxCount, const char* _Format, va_list _ArgList) { return vsnprintf_s(_DstBuf,__size,_MaxCount,_Format,_ArgList); } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,va_list _ArgList);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) _vsnprintf_s(char (&_DstBuf)[__size], size_t _MaxCount, const char* _Format, va_list _ArgList) { return _vsnprintf_s(_DstBuf,__size,_MaxCount,_Format,_ArgList); } }

  __attribute__((dllimport)) int __attribute__((__cdecl__)) vsprintf_s(char *_DstBuf,size_t _Size,const char *_Format,va_list _ArgList);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) vsprintf_s(char (&_DstBuf)[__size], const char* _Format, va_list _ArgList) { return vsprintf_s(_DstBuf,__size,_Format,_ArgList); } }

  __attribute__((dllimport)) int __attribute__((__cdecl__)) sprintf_s(char *_DstBuf,size_t _DstSize,const char *_Format,...);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) sprintf_s(char (&_DstBuf)[__size], const char* _Format, ...) { va_list __vaargs; __builtin_va_start(__vaargs,_Format); int __retval = vsprintf_s(_DstBuf,__size,_Format,__vaargs); __builtin_va_end(__vaargs); return __retval; } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf_s(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,...);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) _snprintf_s(char (&_DstBuf)[__size], size_t _MaxCount, const char* _Format, ...) { va_list __vaargs; __builtin_va_start(__vaargs,_Format); int __retval = _vsnprintf_s(_DstBuf,__size,_MaxCount,_Format,__vaargs); __builtin_va_end(__vaargs); return __retval; } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fprintf_p(FILE *_File,const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _printf_p(const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sprintf_p(char *_Dst,size_t _MaxCount,const char *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfprintf_p(FILE *_File,const char *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vprintf_p(const char *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsprintf_p(char *_Dst,size_t _MaxCount,const char *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scprintf_p(const char *_Format,...);
  __attribute__((dllimport)) int __attribute__((__cdecl__)) _vscprintf_p(const char *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _printf_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _printf_p_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vprintf_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vprintf_p_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fprintf_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fprintf_p_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfprintf_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfprintf_p_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sprintf_l(char *_DstBuf,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sprintf_p_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsprintf_l(char *_DstBuf,const char *_Format,_locale_t,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsprintf_p_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scprintf_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scprintf_p_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscprintf_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscprintf_p_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _printf_s_l(const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vprintf_s_l(const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fprintf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfprintf_s_l(FILE *_File,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _sprintf_s_l(char *_DstBuf,size_t _DstSize,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsprintf_s_l(char *_DstBuf,size_t _DstSize,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf_s_l(char *_DstBuf,size_t _DstSize,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snprintf_c_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf_l(char *_DstBuf,size_t _MaxCount,const char *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnprintf_c_l(char *_DstBuf,size_t _MaxCount,const char *,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) fopen_s(FILE **_File,const char *_Filename,const char *_Mode);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) freopen_s(FILE** _File, const char *_Filename, const char *_Mode, FILE *_Stream);

  __attribute__ ((__dllimport__)) char* __attribute__((__cdecl__)) gets_s(char*,rsize_t);
  extern "C++" { template <size_t __size> inline char* __attribute__((__cdecl__)) get_s(char (&_DstBuf)[__size]) { return get_s(_DstBuf,__size); } }

  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) tmpnam_s(char*,rsize_t);
  extern "C++" { template <size_t __size> inline errno_t __attribute__((__cdecl__)) tmpnam_s(char (&_DstBuf)[__size]) { return tmpnam_s(_DstBuf,__size); } }




  __attribute__ ((__dllimport__)) wchar_t *__attribute__((__cdecl__)) _getws_s(wchar_t *_Str,size_t _SizeInWords);
  extern "C++" { template <size_t __size> inline wchar_t* __attribute__((__cdecl__)) _getws_s(wchar_t (&_DstBuf)[__size]) { return _getws_s(_DstBuf,__size); } }

  int __attribute__((__cdecl__)) fwprintf_s(FILE *_File,const wchar_t *_Format,...);
  int __attribute__((__cdecl__)) wprintf_s(const wchar_t *_Format,...);
  int __attribute__((__cdecl__)) vfwprintf_s(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  int __attribute__((__cdecl__)) vwprintf_s(const wchar_t *_Format,va_list _ArgList);

  int __attribute__((__cdecl__)) vswprintf_s(wchar_t *_Dst,size_t _SizeInWords,const wchar_t *_Format,va_list _ArgList);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) vswprintf_s(wchar_t (&_Dst)[__size], const wchar_t* _Format, va_list _ArgList) { return vswprintf_s(_Dst,__size,_Format,_ArgList); } }

  int __attribute__((__cdecl__)) swprintf_s(wchar_t *_Dst,size_t _SizeInWords,const wchar_t *_Format,...);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) swprintf_s(wchar_t (&_Dst)[__size], const wchar_t* _Format, ...) { va_list __vaargs; __builtin_va_start(__vaargs,_Format); int __retval = vswprintf_s(_Dst,__size,_Format,__vaargs); __builtin_va_end(__vaargs); return __retval; } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,const wchar_t *_Format,va_list _ArgList);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) _vsnwprintf_s(wchar_t (&_DstBuf)[__size], size_t _MaxCount, const wchar_t* _Format, va_list _ArgList) { return _vsnwprintf_s(_DstBuf,__size,_MaxCount,_Format,_ArgList); } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,const wchar_t *_Format,...);
  extern "C++" { template <size_t __size> inline int __attribute__((__cdecl__)) _snwprintf_s(wchar_t (&_DstBuf)[__size], size_t _MaxCount, const wchar_t* _Format, ...) { va_list __vaargs; __builtin_va_start(__vaargs,_Format); int __retval = _vsnwprintf_s(_DstBuf,__size,_MaxCount,_Format,__vaargs); __builtin_va_end(__vaargs); return __retval; } }


  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wprintf_s_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vwprintf_s_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwprintf_s_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfwprintf_s_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwscanf_s_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swscanf_s_l(const wchar_t *_Src,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) swscanf_s(const wchar_t *_Src,const wchar_t *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwscanf_s(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwscanf_s_l(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wscanf_s_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wfopen_s(FILE **_File,const wchar_t *_Filename,const wchar_t *_Mode);
  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wfreopen_s(FILE **_File,const wchar_t *_Filename,const wchar_t *_Mode,FILE *_OldFile);

  __attribute__ ((__dllimport__)) errno_t __attribute__((__cdecl__)) _wtmpnam_s(wchar_t *_DstBuf,size_t _SizeInWords);
  extern "C++" { template <size_t __size> inline errno_t __attribute__((__cdecl__)) _wtmpnam_s(wchar_t (&_DstBuf)[__size]) { return _wtmpnam_s(_DstBuf,__size); } }

  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwprintf_p(FILE *_File,const wchar_t *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wprintf_p(const wchar_t *_Format,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfwprintf_p(FILE *_File,const wchar_t *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vwprintf_p(const wchar_t *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,...);
  __attribute__((dllimport)) int __attribute__((__cdecl__)) _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scwprintf_p(const wchar_t *_Format,...);
  __attribute__((dllimport)) int __attribute__((__cdecl__)) _vscwprintf_p(const wchar_t *_Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwprintf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwprintf_p_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfwprintf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vfwprintf_p_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scwprintf_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _scwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscwprintf_p_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) __swprintf_l(wchar_t *_Dest,const wchar_t *_Format,_locale_t _Plocinfo,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) __vswprintf_l(wchar_t *_Dest,const wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _vscwprintf_l(const wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _fwscanf_l(FILE *_File,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _swscanf_l(const wchar_t *_Src,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _snwscanf_l(const wchar_t *_Src,size_t _MaxCount,const wchar_t *_Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __attribute__((__cdecl__)) _wscanf_l(const wchar_t *_Format,_locale_t _Locale,...);



  __attribute__ ((__dllimport__)) size_t __attribute__((__cdecl__)) _fread_nolock_s(void *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);


}
# 1035 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 2 3

# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/_mingw_print_pop.h" 1 3
# 1037 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/x86_64-w64-mingw32/include/stdio.h" 2 3
# 37 "G:/Repo/hls_project/src/BWT.h" 2
# 1 "C:/Xilinx/Vivado/2019.2/tps/win64/msys64/mingw64/include/c++/6.2.0/stdlib.h" 1 3
# 38 "G:/Repo/hls_project/src/BWT.h" 2
# 50 "G:/Repo/hls_project/src/BWT.h"

# 50 "G:/Repo/hls_project/src/BWT.h"
int BWT(const unsigned char* T, unsigned char* U, int* SA, int n);
# 62 "G:/Repo/hls_project/src/BWT.h"
int UnBWT(const unsigned char* T, unsigned char* U, int n, int pidx);


}
# 28 "G:/Repo/hls_project/src/BWT.cpp" 2






static void getCounts(const unsigned char* T, int* C, int n, int k, int cs)
{
  int i;
  for (i = 0; i < k; ++i) {
    C[i] = 0;
  }
  for (i = 0; i < n; ++i) {
    ++C[(cs == sizeof(int) ? ((const int*) T)[i] : ((const unsigned char*) T)[i])];
  }
}
static void getBuckets(const int* C, int* B, int k, int end)
{
  int i, sum = 0;
  if (end) {
    for (i = 0; i < k; ++i) {
      sum += C[i];
      B[i] = sum;
    }
  }
  else {
    for (i = 0; i < k; ++i) {
      sum += C[i];
      B[i] = sum - C[i];
    }
  }
}


static void induceSA(const unsigned char* T, int* SA, int* C, int* B, int n,
                     int k, int cs)
{
  int *b, i, j;
  int c0, c1;

  if (C == B) {
    getCounts(T, C, n, k, cs);
  }
  getBuckets(C, B, k, 0);
  j = n - 1;
  b = SA + B[c1 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j])];
  *b++ = ((0 < j) && ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) < c1)) ? ~j : j;
  for (i = 0; i < n; ++i) {
    j = SA[i], SA[i] = ~j;
    if (0 < j) {
      --j;
      if ((c0 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j])) != c1) {
        B[c1] = (int) (b - SA);
        b = SA + B[c1 = c0];
      }
      *b++ = ((0 < j) && ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) < c1)) ? ~j : j;
    }
  }

  if (C == B) {
    getCounts(T, C, n, k, cs);
  }
  getBuckets(C, B, k, 1);
  for (i = n - 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if (0 < (j = SA[i])) {
      --j;
      if ((c0 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j])) != c1) {
        B[c1] = (int) (b - SA);
        b = SA + B[c1 = c0];
      }
      *--b = ((j == 0) || ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) > c1)) ? ~j : j;
    }
    else {
      SA[i] = ~j;
    }
  }
}
static int computeBWT(const unsigned char* T, int* SA, int* C, int* B, int n,
                      int k, int cs)
{
  int *b, i, j, pidx = -1;
  int c0, c1;

  if (C == B) {
    getCounts(T, C, n, k, cs);
  }
  getBuckets(C, B, k, 0);
  j = n - 1;
  b = SA + B[c1 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j])];
  *b++ = ((0 < j) && ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) < c1)) ? ~j : j;
  for (i = 0; i < n; ++i) {
    if (0 < (j = SA[i])) {
      --j;
      SA[i] = ~(c0 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j]));
      if (c0 != c1) {
        B[c1] = (int) (b - SA);
        b = SA + B[c1 = c0];
      }
      *b++ = ((0 < j) && ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) < c1)) ? ~j : j;
    }
    else if (j != 0) {
      SA[i] = ~j;
    }
  }

  if (C == B) {
    getCounts(T, C, n, k, cs);
  }
  getBuckets(C, B, k, 1);
  for (i = n - 1, b = SA + B[c1 = 0]; 0 <= i; --i) {
    if (0 < (j = SA[i])) {
      --j;
      SA[i] = (c0 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j]));
      if (c0 != c1) {
        B[c1] = (int) (b - SA);
        b = SA + B[c1 = c0];
      }
      *--b = ((0 < j) && ((cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1]) > c1)) ? ~((int) (cs == sizeof(int) ? ((const int*) T)[j - 1] : ((const unsigned char*) T)[j - 1])) : j;
    }
    else if (j != 0) {
      SA[i] = ~j;
    }
    else {
      pidx = i;
    }
  }
  return pidx;
}




static int suffixsort(const unsigned char* T, int* SA, int fs, int n, int k,
                      int cs, int isbwt)
{
  int *C, *B, *RA;
  int i, j, c, m, p, q, plen, qlen, name, pidx = 0;
  int c0, c1;
  int diff;




  if ((1 * k) <= fs) {
    C = SA + n;
    B = ((1 < 1) || (k <= (fs - k))) ? C + k : C;
  }
  else {
    if ((C = (int*) malloc(1 * k * sizeof(int))) == 
# 176 "G:/Repo/hls_project/src/BWT.cpp" 3 4
                                                            __null
# 176 "G:/Repo/hls_project/src/BWT.cpp"
                                                                ) {
      return -2;
    }
    B = (1 < 1) ? C + k : C;
  }
  getCounts(T, C, n, k, cs);
  getBuckets(C, B, k, 1);
  for (i = 0; i < n; ++i) {
    SA[i] = 0;
  }
  for (i = n - 2, c = 0, c1 = (cs == sizeof(int) ? ((const int*) T)[n - 1] : ((const unsigned char*) T)[n - 1]); 0 <= i; --i, c1 = c0) {
    if ((c0 = (cs == sizeof(int) ? ((const int*) T)[i] : ((const unsigned char*) T)[i])) < (c1 + c)) {
      c = 1;
    }
    else if (c != 0) {
      SA[--B[c1]] = i + 1, c = 0;
    }
  }
  induceSA(T, SA, C, B, n, k, cs);
  if (fs < (1 * k)) {
    free(C);
  }



  for (i = 0, m = 0; i < n; ++i) {
    p = SA[i];
    if ((0 < p) && ((cs == sizeof(int) ? ((const int*) T)[p - 1] : ((const unsigned char*) T)[p - 1]) > (c0 = (cs == sizeof(int) ? ((const int*) T)[p] : ((const unsigned char*) T)[p])))) {
      for (j = p + 1; (j < n) && (c0 == (c1 = (cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j]))); ++j) {}
      if ((j < n) && (c0 < c1)) {
        SA[m++] = p;
      }
    }
  }
  j = m + (n >> 1);
  for (i = m; i < j; ++i) {
    SA[i] = 0;
  }

  for (i = n - 2, j = n, c = 0, c1 = (cs == sizeof(int) ? ((const int*) T)[n - 1] : ((const unsigned char*) T)[n - 1]); 0 <= i; --i, c1 = c0) {
    if ((c0 = (cs == sizeof(int) ? ((const int*) T)[i] : ((const unsigned char*) T)[i])) < (c1 + c)) {
      c = 1;
    }
    else if (c != 0) {
      SA[m + ((i + 1) >> 1)] = j - i - 1;
      j = i + 1;
      c = 0;
    }
  }

  for (i = 0, name = 0, q = n, qlen = 0; i < m; ++i) {
    p = SA[i], plen = SA[m + (p >> 1)], diff = 1;
    if (plen == qlen) {
      for (j = 0; (j < plen) && ((cs == sizeof(int) ? ((const int*) T)[p + j] : ((const unsigned char*) T)[p + j]) == (cs == sizeof(int) ? ((const int*) T)[q + j] : ((const unsigned char*) T)[q + j])); ++j) {}
      if (j == plen) {
        diff = 0;
      }
    }
    if (diff != 0) {
      ++name, q = p, qlen = plen;
    }
    SA[m + (p >> 1)] = name;
  }



  if (name < m) {
    RA = SA + n + fs - m;
    for (i = m + (n >> 1) - 1, j = m - 1; m <= i; --i) {
      if (SA[i] != 0) {
        RA[j--] = SA[i] - 1;
      }
    }
    if (suffixsort((unsigned char*) RA, SA, fs + n - m * 2, m, name,
                   sizeof(int), 0) != 0) {
      return -2;
    }
    for (i = n - 2, j = m - 1, c = 0, c1 = (cs == sizeof(int) ? ((const int*) T)[n - 1] : ((const unsigned char*) T)[n - 1]); 0 <= i; --i, c1 = c0) {
      if ((c0 = (cs == sizeof(int) ? ((const int*) T)[i] : ((const unsigned char*) T)[i])) < (c1 + c)) {
        c = 1;
      }
      else if (c != 0) {
        RA[j--] = i + 1, c = 0;
      }
    }
    for (i = 0; i < m; ++i) {
      SA[i] = RA[SA[i]];
    }
  }


  if ((1 * k) <= fs) {
    C = SA + n;
    B = ((1 < 1) || (k <= (fs - k))) ? C + k : C;
  }
  else {
    if ((C = (int*) malloc(1 * k * sizeof(int))) == 
# 272 "G:/Repo/hls_project/src/BWT.cpp" 3 4
                                                            __null
# 272 "G:/Repo/hls_project/src/BWT.cpp"
                                                                ) {
      return -2;
    }
    B = (1 < 1) ? C + k : C;
  }

  getCounts(T, C, n, k, cs);
  getBuckets(C, B, k, 1);
  for (i = m; i < n; ++i) {
    SA[i] = 0;
  }
  for (i = m - 1; 0 <= i; --i) {
    j = SA[i], SA[i] = 0;
    SA[--B[(cs == sizeof(int) ? ((const int*) T)[j] : ((const unsigned char*) T)[j])]] = j;
  }
  if (isbwt == 0) {
    induceSA(T, SA, C, B, n, k, cs);
  }
  else {
    pidx = computeBWT(T, SA, C, B, n, k, cs);
  }
  if (fs < (1 * k)) {
    free(C);
  }

  return pidx;

}

int BWT(const unsigned char* T, unsigned char* U, int* SA, int n)
{
  int i, pidx;
  if ((T == 
# 304 "G:/Repo/hls_project/src/BWT.cpp" 3 4
           __null
# 304 "G:/Repo/hls_project/src/BWT.cpp"
               ) || (U == 
# 304 "G:/Repo/hls_project/src/BWT.cpp" 3 4
                          __null
# 304 "G:/Repo/hls_project/src/BWT.cpp"
                              ) || (n < 0)) {
    return -1;
  }
  if (n <= 1) {
    if (n == 1) {
      U[0] = T[0];
    }
    return n;
  }

  int* A = (int*) malloc(n * sizeof(int));
  if (A == 
# 315 "G:/Repo/hls_project/src/BWT.cpp" 3 4
          __null
# 315 "G:/Repo/hls_project/src/BWT.cpp"
              ) {
    return -1;
  }


  suffixsort(T, SA, 0, n, 256, sizeof(unsigned char), 0);


  pidx = suffixsort(T, A, 0, n, 256, sizeof(unsigned char), 1);
  if (pidx < 0) {
    free(A);
    return pidx;
  }
  U[0] = T[n - 1];
  for (i = 0; i < pidx; ++i) {
    U[i + 1] = (unsigned char) A[i];
  }
  i += 1;
  for (; i < n; ++i) {
    U[i] = (unsigned char) A[i];
  }
  free(A);
  return pidx + 1;
}


int UnBWT(const unsigned char* T, unsigned char* U, int n, int pidx)
{
  unsigned int C[256];
  unsigned char D[256];
  int i, p;
  int c, d, len, half;

  if ((T == 
# 348 "G:/Repo/hls_project/src/BWT.cpp" 3 4
           __null
# 348 "G:/Repo/hls_project/src/BWT.cpp"
               ) || (n < 0) || (pidx < 0) || (n < pidx) ||
      ((0 < n) && (pidx == 0))) {
    return -1;
  }
  if (n <= 1) {
    if (n == 1) {
      U[0] = T[0];
    }
    return 0;
  }

  int* A = (int*) malloc(n * sizeof(int));
  if (A == 
# 360 "G:/Repo/hls_project/src/BWT.cpp" 3 4
          __null
# 360 "G:/Repo/hls_project/src/BWT.cpp"
              ) {
    return -1;
  }

  if (n <= (1 << 24)) {

    unsigned int* B = (unsigned int*) A;
    for (c = 0; c < 256; ++c) {
      C[c] = 0;
    }
    for (i = 0; i < n; ++i) {
      B[i] = (C[T[i]]++ << 8) | T[i];
    }
    for (c = 0, i = 0; c < 256; ++c) {
      p = C[c];
      C[c] = i;
      i += p;
    }
    for (i = n - 1, p = 0; 0 <= i; --i) {
      p = (B[p] >> 8) + C[U[i] = (unsigned char) (B[p] & 0xff)];
      if (p < pidx) {
        ++p;
      }
    }
  }
  else if (T != U) {

    for (c = 0; c < 256; ++c) {
      C[c] = 0;
    }
    for (i = 0; i < n; ++i) {
      A[i] = C[T[i]]++;
    }
    for (c = 0, i = 0; c < 256; ++c) {
      p = C[c];
      C[c] = i;
      i += p;
    }
    for (i = n - 1, p = 0; 0 <= i; --i) {
      p = A[p] + C[U[i] = T[p]];
      if (p < pidx) {
        ++p;
      }
    }
  }
  else {

    for (c = 0; c < 256; ++c) {
      C[c] = 0;
    }
    for (i = 0; i < n; ++i) {
      ++C[T[i]];
    }
    for (c = 0, d = 0, i = 0; c < 256; ++c) {
      p = C[c];
      if (0 < p) {
        C[c] = i;
        D[d++] = (unsigned char) c;
        i += p;
      }
    }
    for (i = 0; i < pidx; ++i) {
      A[C[T[i]]++] = i;
    }
    for (; i < n; ++i) {
      A[C[T[i]]++] = i + 1;
    }
    for (c = 0; c < d; ++c) {
      C[c] = C[D[c]];
    }
    for (i = 0, p = pidx; i < n; ++i) {
      for (c = 0, len = d, half = len >> 1; 0 < len; len = half, half >>= 1) {
        if (C[c + half] < (unsigned int) p) {
          c += half + 1;
          half -= (len & 1) ^ 1;
        }
      }
      U[i] = D[c];
      p = A[p - 1];
    }
  }
  free(A);
  return 0;
}
