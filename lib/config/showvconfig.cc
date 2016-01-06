#include <config.h>
#include <limits.h>
#include <unistd.h>
#include "misc/pwentry.h"
#include "vdomain/vdomain.h"
#include "configrc.h"
#include "fdbuf/fdbuf.h"

template<class T>
void show_val(const char* name, T value)
{
  fout << name << ": " << value << "\n\n";
}

void show_uns(const char* name, unsigned value)
{
  fout << name << ": ";
  if(value == UINT_MAX)
    fout << "-1\n\n";
  else
    fout << value << "\n\n";
}

void show_list(const char* name, const strlist& value)
{
  if(!value)
    fout << name << " is empty.\n";
  else
    for(mystring_iter iter(value.str()); iter; ++iter)
      fout << name << ": " << *iter << "\n";
  fout << "\n";
}

#define show_dir show_val
#define show_str show_val

pwentry user;
vdomain domain(user);

bool go_home()
{
  if(!user.home) {
    ferr << "showvconfig: Can't determine home directory" << endl;
    return false;
  }
  if(chdir(user.home.c_str()) == -1) {
    ferr << "showvconfig: Can't change to home directory" << endl;
    return false;
  }
  config = &domain.config;
  return true;
}

int main()
{
  if(!go_home())
    return 1;
  show_dir("autoresponse-dir", config->autoresponse_dir());
  show_str("autoresponse-file", config->autoresponse_file());
  show_dir("bulletin-dir", config->bulletin_dir());
  show_uns("default-expiry", config->default_expiry());
  show_dir("default-maildir", config->default_maildir());
  show_uns("default-msgcount", config->default_msgcount());
  show_uns("default-msgsize", config->default_msgsize());
  show_uns("default-hardquota", config->default_hardquota());
  show_uns("default-softquota", config->default_softquota());
  show_str("default-username", config->default_username());
  show_dir("error-maildir", config->error_maildir());
  show_dir("global-bulletin-dir", config->global_bulletin_dir());
  show_str("maildir-arg-str", config->maildir_arg_str());
  show_str("password-file", config->password_file());
  show_list("postmaster-aliases", config->postmaster_aliases());
  show_str("postmaster-email", config->postmaster_email());
  show_dir("qmail-root", config->qmail_root());
  show_str("separators", config->separators());
  show_str("socket-file", config->socket_file());
  show_dir("user-dir", config->user_dir());
  show_uns("user-dir-bits", config->user_dir_bits());
  show_uns("user-dir-slices", config->user_dir_slices());
  return 0;
}
