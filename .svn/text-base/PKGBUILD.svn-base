# Contributor: b4d <baccic@gmail.com>

pkgname=darts
pkgver=1
pkgrel=1
pkgdesc="Point counter for dart games"
arch=('i686' 'x86_64')
provides=('darts')
conflicts=('darts')
options=()
license=('GPL')
url=""
depends=('sysvbanner')
makedepends=()
source=()
md5sums=()
_svntrunk=svn://
_svnmod=gajim


build() {
    cd $startdir/src
    msg "Updating darts SVN..."
    svn co $_svntrunk -r $pkgver $_svnmod
    msg "SVN checkout done or server timeout"
    msg "Starting make..."
    cd $startdir/src/$_svnmod
    # For my regular daily builds
    make clean
    ./autogen.sh --prefix=/usr
    make
    make DESTDIR=$startdir/pkg install
}
