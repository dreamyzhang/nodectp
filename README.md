# windows
```
#初始化c++编译环境
npm install --global --production windows-build-tools
cp binding-windows.gyp  binding.gy
node-gyp rebuild
node ./test/mduser.js
#node ./test/tduser.js
```
# linux
```
cp binding-windows.gyp  binding.gy
node-gyp rebuild
node ./test/mduser.js
#node ./test/tduser.js
```
