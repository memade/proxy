#if !defined(__E6BD0200_6525_4BE2_B08A_125B540328F7__)
#define __E6BD0200_6525_4BE2_B08A_125B540328F7__

namespace local {
 class Server {
 public:
  Server();
  ~Server();
 private:
  void Init();
  void UnInit();
 public:
  bool Ready() const;
 private:
  std::atomic_bool m_IsOpen = false;
  libuvpp::ILibuv* m_pLibuv = nullptr;
  libuvpp::IProxyTcp* m_pLibuvServer = nullptr;
 private:
  void OnMessage(libuvpp::ISession*, const std::string&);
  void OnConnect(libuvpp::ISession*);
  void OnDisconnect(libuvpp::ISession*);
 };
}

/// /*_ Memade®（新生™） _**/
/// /*_ Wed, 25 Jan 2023 00:29:53 GMT _**/
/// /*_____ https://www.skstu.com/ _____ **/
#endif///__E6BD0200_6525_4BE2_B08A_125B540328F7__


