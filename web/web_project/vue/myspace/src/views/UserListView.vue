<template>
    <ContentBase>
        <div class="card" v-for="user in users" :key="user.id" @click="open_user_profile(user.id)">
            <div class="card-body">
                <div class="row">
                    <div class="col-1 img-field">
                        <img :src="user.photo" class="img-fluid" alt="user-profile-photo">
                    </div>
                    <div class="col-11">
                        <div class="username">{{ user.username }}</div>
                        <div class="followerCount">{{ user.followerCount }}</div>
                    </div>
                </div>
            </div>
        </div>
    </ContentBase>
</template>

<script>
import ContentBase from '../components/CoetentBase';   
import $ from 'jquery';
import { ref } from 'vue';
import router from '@/router/index'; // @默认为src目录
import { useStore } from 'vuex'

export default {
    name: 'UserListView',
    components: {
        ContentBase,
    },
    setup() {
        const store = useStore();
        let users = ref([]);
        // 注意只有切换到该页面时才会调用GET,并且每次切换都会重新调用
        $.ajax({
            url: "https://app165.acapp.acwing.com.cn/myspace/userlist/",
            type: "get",
            success: function(resp){
                users.value = resp;
            }
        });
        const open_user_profile = userID => {
            // 如果已经登陆就跳转到用户界面
            if(store.state.user.is_login) {
                router.push({
                    name: 'userprofile',
                    params: {
                        // 注意如果要使用简写形式千万不能写错字母了
                        // 如果我们传入的参数是userId，那么要写为：
                        // userID: userId,
                        userID, 
                    }
                })
            }
            // 如果没有登录就跳转到登录界面
            else {
                router.push({
                    name: 'login'
                });
            }
        }
        return {
            users,
            open_user_profile,
        }
    }
}
</script>

<!-- 别忘记加scoped -->
<style scoped>
.username {
    font-weight: bold;
    height: 50%;
}

.followerCount {
    font-size: 12px;
    color: gray;
    height: 50%;
}

.card {
    margin-bottom: 20px;
    cursor: pointer; /* 这样当用户鼠标触碰到用户时,会改变鼠标指针,提示用户该区域可以点击跳转 */
}

.card:hover {
    box-shadow: 2px 2px 10px lightgreen;
}

.img{
    border-radius: 50%;
}

.img-field {
    display: flex;
    flex-direction: column;
    justify-content: center;
}
</style>