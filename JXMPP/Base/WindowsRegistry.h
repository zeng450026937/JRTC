#ifndef JXMPP_WINDOWSREGISTRY_H
#define JXMPP_WINDOWSREGISTRY_H

#include <windows.h>
#include <tchar.h>

namespace JXMPP {
    class WindowsRegistry {
        public:
            static bool isFIPSEnabled() {
                TCHAR* pathForXP = _TEXT("System\\CurrentControlSet\\Control\\Lsa");
                TCHAR* pathSinceVista = _TEXT("System\\CurrentControlSet\\Control\\Lsa\\FIPSAlgorithmPolicy");
                TCHAR* keyForXP = _TEXT("FIPSAlgorithmPolicy");
                TCHAR* keySinceVista = _TEXT("Enabled");

                OSVERSIONINFO osvi;
                ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
                osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
                GetVersionEx(&osvi);

                TCHAR* keyForOS = osvi.dwMajorVersion < 6 ? keyForXP : keySinceVista;
                TCHAR* pathForOS = osvi.dwMajorVersion < 6 ? pathForXP : pathSinceVista;

                /* http://support.microsoft.com/kb/811833 */
                /* http://msdn.microsoft.com/en-us/library/ms724911%28VS.85%29.aspx */
                HKEY key;
                bool result = false;
                if (RegOpenKeyEx(HKEY_LOCAL_MACHINE,
                            pathForOS,
                            0,
                            KEY_READ,
                            &key) != ERROR_SUCCESS) {
                    /* If we can't find the key that says we're FIPS, we're not FIPS */
                    return result;
                }
                DWORD keyType = REG_DWORD;
                DWORD data;
                DWORD length = sizeof(data);

                if (RegQueryValueEx(key,
                        keyForOS,
                        NULL,
                        &keyType,
                        (LPBYTE)&data,
                        &length) == ERROR_SUCCESS) {
                    result = data != 0;
                }

                RegCloseKey(key);
                return result;
            }
    };
}

#endif // JXMPP_WINDOWSREGISTRY_H
