import $ from 'jquery'
import { jwtDecode } from 'jwt-decode'

// dispatch：调用actions里面的函数
// commit：调用mutations里面的函数

const moduleUser = {
    state: {
        id: "",
        username: "",
        photo: "",
        followCount: 0,
        access: "",
        refresh: "",
        is_login: false,
    },
    getters: {
    },
    // action用来写逻辑,mutation用来修改state
    mutations: {
        // 第一个参数固定为state?
        updateUser(state, user) {
            state.id          = user.id;
            state.username    = user.username;
            state.photo       = user.photo;
            state.followCount = user.followCount;
            state.access      = user.access;
            state.refresh     = user.refresh;
            state.is_login    = user.is_login;
        },
        updateAccess(state, access) {
            state.access = access;
        },
        logout(state) {
            // 推出后清空state
            state.id          = "";
            state.username    = "";
            state.photo       = "";
            state.followCount = "";
            state.access      = "";
            state.refresh     = "";
            state.is_login    = false;
        },
    },
    actions: {
        // 第一个参数固定为context 
        login(context, data) {
            $.ajax({
                url: "https://app165.acapp.acwing.com.cn/api/token/", 
                type: "POST",
                data: { // 这个data是我们传给服务器的参数
                    username: data.username,
                    password: data.password,
                },
                success(resp) {
                    const {access, refresh} = resp;
                    const access_obj = jwtDecode(access);

                    setInterval(() => {
                        $.ajax({
                            url: 'https://app165.acapp.acwing.com.cn/api/token/refresh/',
                            type: 'POST',
                            data: {
                                refresh, 
                            },
                            success(resp) {
                                context.comit('updateAccess', resp.access);
                            },
                        });
                    }, 4.5 * 60 * 1000);  // 5minutes,但是为了避免边界情况/网络波动问题，设置为4.5分钟一次

                    $.ajax({
                        url: 'https://app165.acapp.acwing.com.cn/myspace/getinfo/',
                        type: "GET",
                        data: {
                            user_id: access_obj.user_id,
                        },
                        headers: {
                            // 授权,格式就是如此,人为定义,注意空格必须要有
                            'Authorization': 'Bearer ' + access,
                        },
                        success(resp) {
                            context.commit("updateUser", {
                                ...resp,
                                access: access, // 不可以直接写成access?
                                refresh: refresh,
                                is_login: true,
                            });
                            // callback funtion
                            // 这里的data::success是data中传入的参数
                            // 注意不要与ajax的data混了
                            // 在LoginView.vue里面
                            data.success();
                        },
                    })
                },
                // callback function
                error() {
                    data.error();
                }
            });
        },
    },
    modules: {
    }
}

export default moduleUser;