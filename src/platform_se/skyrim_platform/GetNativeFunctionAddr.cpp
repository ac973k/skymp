#include "GetNativeFunctionAddr.h"
#include <RE\BSScript\NF_util\NativeFunctionBase.h>

GetNativeFunctionAddr::Result GetNativeFunctionAddr::Run(
  const RE::BSScript::IFunction& f)
{
  auto addrPtr = reinterpret_cast<const size_t*>(
    reinterpret_cast<const uint8_t*>(&f) +
    sizeof(RE::BSScript::NF_util::NativeFunctionBase));
  auto nativeFn = reinterpret_cast<void*>(*addrPtr);

  auto useLongSignaturePtr = reinterpret_cast<const bool*>(
    reinterpret_cast<const uint8_t*>(addrPtr) + sizeof(void*));

  return { nativeFn, *useLongSignaturePtr };
}
