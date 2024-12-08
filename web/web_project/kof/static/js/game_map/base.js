import { AcGameObject } from "/static/js/ac_game_object/base.js"

// 在动画中一般先初始化一个canvas


// kof *root = new root;
class GameMap extends AcGameObject {
    constructor(root) {
        super();

        this.$canvas = $('<canvas width="1280" height="720" tabindex=0></canvas>');
        this.ctx = this.$canvas.getContext("2d");
        this.root.$kof.append(this.$canvas);
        this.$canvas.focus(); 
    }

    start() {

    }

    update() {
        this.render();
    }

    // 清空（轨迹），如果不清空的话动画是一条轨迹，但不是动画
    render() {
        this.ctx.clearRect(0, 0, this.);
    }
}