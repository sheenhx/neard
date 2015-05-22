# neard
NFC user space tool for TRF7970A

#Linux-nfc is a opensource stack tool to support TRF7970A. However, its website just has the HOWTOs of the PC platfom.


Our MT7620 platform is ramips structure, and thus we need cross compile the tool to the ramips platform, which need the Openwrt SDK.

```
http://wiki.openwrt.org/doc/devel/crosscompile
```
Download the SDK here: 
```
https://downloads.openwrt.org/snapshots/trunk/ramips/mt7620/
```


Git clone the neard: 
```
git clone https://github.com/sheenhx/neard.git
```
In the Host PC you should apt-get install the necessary libraries in HOWTOs.

```
https://01.org/linux-nfc/documentation/howtos
```
Export the PATH to the Openwrt SDK and modify the bootstrap-configure in neard folder:

```
export TOOLCHAIN=/opt/cross/mipsel/7620/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2 
export PATH="$TOOLCHAIN/bin:$PATH"
export PATH="/home/sheen/trunk/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin:$PATH"
STAGING_DIR=/home/sheen/trunk/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2
export STAGING_DIR
```

modify bootstrap-configure:

```
./configure --enable-maintainer-mode \
    --enable-debug \
        --disable-systemd \
        --prefix=/home/sheen/nfc/usr \
        --exec-prefix=/home/sheen/nfc/usr\
        --sysconfdir=/home/sheen/nfc/etc \
        --host=mipsel-openwrt-linux-uclibc \
        MANIFEST_TOOL=: \
        CC=mipsel-openwrt-linux-uclibc-gcc-4.8.3 \
        LD=mipsel-openwrt-linux-uclibc-ld \
        RANLIB=mipsel-openwrt-uclibc-ranlib \
        LDFLAGS=-L/home/sheen/trunk/OpenWrt-SDK-ramips-mt7620_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/staging_dir/target-mipsel_24kec+dsp_uClibc-0.9.33.2/usr/lib
```

And follow the other instructions in HOWTOs, copy the files in prefix folder and copy the test folder to the target Openwrt system.
