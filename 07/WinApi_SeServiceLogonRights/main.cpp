/// Разбираем MSDN
/// ==============
// SeServiceLogonRight
#include <iostream>
#include <ntsecapi.h>


using namespace std;

int main() {
  // 1. Открыть политики безопасности LsaOpenPolicy().
  // To grant privileges, open the policy with POLICY_CREATE_ACCOUNT and POLICY_LOOKUP_NAMES access.
  // To revoke privileges, open the policy with POLICY_LOOKUP_NAMES access.
  LsaOpenPolicy(
    Server,
    &ObjectAttributes,
    DesiredAccess,
    PolicyHandle
  );

  // 2. Получаем данные о пользователе (SID) по имени пользователя
  // Obtain a SID (security identifier) representing the user/group of interest. The
  // LookupAccountName() and LsaLookupNames() APIs can obtain a SID from an account name.


  // 3. Вызываем функцию добавления прав LsaAddAccountRights() to
  // grant privileges to the user(s) represented by the supplied SID.

  // 4. Закрываем политики с помощью LsaClose().

  return 0;
}