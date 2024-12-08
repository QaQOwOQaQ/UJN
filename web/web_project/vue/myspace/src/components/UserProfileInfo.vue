<template>
    <div class="card">
        <div class="card-body">
            <div class="row">
                <div class="col-3 img-field">
                    <!-- 加上冒号就可以让字符串中的内容作为变量解释 -->
                    <img :src="user.photo" class="img-fluid" alt="Acwing-Profile-Photo" >
                </div>
                <div class="col-9">
                    <div class="username">{{ user.username }}</div>
                    <div class="fans">fans: {{ user.followCount }}</div>
                    <button @click="follow" v-if="!user.is_followed" type="button" class="btn btn-secondary btn-sm">+follow</button>
                    <button v-on:click="unfollow" v-if="user.is_followed" type="button" class="btn btn-secondary btn-sm">haveFollowed</button>
                </div>
            </div>
        </div>  
    </div>
</template>

<script>
import { computed } from 'vue'
import $ from 'jquery'
import { useStore } from 'vuex'

export default {
    name: 'UserProfileInfo',
    props: {
        user: {
            type: Object,   // 注意大小写
            required: true,
        },
    },
    setup(props, context) {
        let fullName = computed(() => props.user.firstName + ' ' + props.user.lastName);
        const store = useStore();

        // 这里的follow修改的是后端的内容
        // 我们只需要传入被关注用户的id
        // 登录用户的id应该是被api直接处理了
        const follow = () => {
            $.ajax({
                url: 'https://app165.acapp.acwing.com.cn/myspace/follow/',
                type: 'POST',
                data: {
                    target_id: props.user.id,   // 被关注用户的id
                },
                headers: {
                    'Authorization': 'Bearer ' + store.state.user.access,
                },
                success(resp) {
                    if(resp.result == "success") {
                        context.emit('follow');
                    }
                }
            })
        }

        const unfollow = () => {
            $.ajax({
                url: 'https://app165.acapp.acwing.com.cn/myspace/follow/',
                type: 'POST',
                data: {
                    target_id: props.user.id,
                },
                headers: {
                    'Authorization': 'Bearer ' + store.state.user.access,
                },
                success(resp) {
                    if(resp.result == "success") {
                        context.emit('unfollow');
                    }
                }
            })
        }
        
        return {
            fullName,
            follow, 
            unfollow,
        }
    }
}
</script>

<style scoped>
img {
    border-radius: 50%; /*将图片设为圆形*/
}
.username {
    font-weight: bold;
}
.fans {
    font-size: 12px;
    color: grey;
}

button {
    padding: 2px 4px;
    font-size: 12px;    
}

.img-field {
    display: flex;
    flex-direction: column;
    justify-content: center;
}
</style>
