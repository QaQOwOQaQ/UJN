<template>
    <div class="card">
        <div class="card-body">
            <div v-for="(post, index) in posts.posts" :key="index">
                <div class="card single-post">
                    <div class="card-body">
                        {{ post.content }}
                        <!-- 只能删除登录用户的post,参数vue后台会自动传入 -->
                        <button @click="delete_post(post.id)" v-if="is_me" type="button" class="btn btn-danger btn-sm">delete</button>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { computed } from 'vue';
import { useStore } from 'vuex'
import $ from 'jquery'

export default {
    name: "UserProfilePosts",
    props: {
        posts: {
            type: Object,
            required: true,
        },
        user: {
            type: Object,
            required: true,
        }
    },
    setup(props, context) {
        const store = useStore();
        // store里面存储的是登录的用户id
        // user里面存储的是当前页面的用户id？
        let is_me = computed(() => {
            return store.state.user.id === props.user.id;
        });

        const delete_post = delete_post_id => {
            // 在后端删除
            $.ajax({
                url: 'https://app165.acapp.acwing.com.cn/myspace/post/',
                type: 'DELETE',
                data: {
                    post_id: delete_post_id,
                },
                headers: {
                    'Authorization': 'Bearer ' + store.state.user.access,
                },
                success(resp) {
                    if(resp.result == "success") {
                        //  在前端删除
                        context.emit('delete_post', delete_post_id);
                    }
                }

            })
        }

        return {
            is_me,
            delete_post,
        }
    }
}
</script>

<style scoped>
.single-post {
    margin-top: 10px;
}

button {
    float: right;
}
</style>