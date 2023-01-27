#if !defined(__F632F833_35ED_4B72_9382_10910C1A8688__)
#define __F632F833_35ED_4B72_9382_10910C1A8688__

namespace local {
 class Global {
 public:
  Global();
  ~Global();
 private:
  void Init();
  void UnInit();
 public:
  static bool Ready();
 private:
  std::atomic_bool m_Ready = false;
  Http* m_pHttp = nullptr;
  Server* m_pServer = nullptr;
 };



 extern Global* __gpGlobal;
}///namespace local


/// /*_ Memade®（新生™） _**/
/// /*_ Wed, 25 Jan 2023 00:29:13 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__F632F833_35ED_4B72_9382_10910C1A8688__


