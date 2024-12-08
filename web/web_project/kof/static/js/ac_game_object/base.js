let AC_GAME_OBJECTS = [];

class AcGameObject {
    constructor() {
        AC_GAME_OBJECTS.push(this);
        this.timedelta = 0;
        this.has_call_start
    }

    // 一般一个动画对象都需要这三个函数
    start() { // 初始执行一次

    }

    update() { // 每一帧执行一次

    }

    destory() { // 删除当前对象
        for(let i in AC_GAME_OBJECTS) {
            if(AC_GAME_OBJECTS[i] == this) {
                AC_GAME_OBJECTS.splice(i, 1);   // 从索引i开始删除1个元素
            }
        }
    }
}


// 一直执行update函数
let last_timestamp;
let AC_GAME_OBJECTS_FRAME = (timestamp) => {
    for(let obj of AC_GAME_OBJECTS) {
        if(!obj.has_call_start) {
            obj.start();
            obj.has_call_start = true;
        }
        else {
            obj.timedelta = timestamp - last_timestamp;
            obj.update();
        }
   }
   last_timestamp = timestamp;
   requestAnimationFrame(AC_GAME_OBJECTS_FRAME);
}

requestAnimationFrame(AC_GAME_OBJECTS_FRAME);