#if !defined(__93D0707C_3932_457E_BBFF_7C4DDBC3A0E7__)
#define __93D0707C_3932_457E_BBFF_7C4DDBC3A0E7__

namespace local {
 class Http {
 public:
  Http();
  ~Http();
 private:
  void Init();
  void UnInit();
 public:
  bool Ready() const;
 private:
  std::atomic_bool m_IsOpen = false;
  libcurlpp::ILibcurlpp* m_pLibcurl = nullptr;
 };
}///namespace local 

/// /*_ Memade®（新生™） _**/
/// /*_ Wed, 25 Jan 2023 00:29:36 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__93D0707C_3932_457E_BBFF_7C4DDBC3A0E7__

