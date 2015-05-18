extern struct near_plugin_desc __near_builtin_nfctype1;
extern struct near_plugin_desc __near_builtin_nfctype2;
extern struct near_plugin_desc __near_builtin_nfctype3;
extern struct near_plugin_desc __near_builtin_nfctype4;
extern struct near_plugin_desc __near_builtin_nfctype5;
extern struct near_plugin_desc __near_builtin_p2p;

static struct near_plugin_desc *__near_builtin[] = {
  &__near_builtin_nfctype1,
  &__near_builtin_nfctype2,
  &__near_builtin_nfctype3,
  &__near_builtin_nfctype4,
  &__near_builtin_nfctype5,
  &__near_builtin_p2p,
  NULL
};
