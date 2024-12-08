<template>
  <ContentBase>
    <div class="row">
      <div class="col-3">
        <UserProfileInfo @follow="follow" @unfollow="unfollow" :user="user" />
        <!-- 是本人才显示编辑页面（发布帖子） -->
        <UserProfileWrite v-if="is_me" @topic_post="topic_post"></UserProfileWrite>
      </div>
      <div class="col-9">
          <!-- 将user,delete_post作为参数传过去 -->
        <UserProfilePosts :user="user" :posts="posts" @delete_post="delete_post" />
      </div>
    </div>
  </ContentBase>
</template>

<script>
import ContentBase from '../components/CoetentBase.vue'
import { reactive } from 'vue'
import UserProfileInfo from '../components/UserProfileInfo.vue'
import UserProfilePosts from '../components/UserProfilePosts.vue'
import UserProfileWrite from '../components/UserProfileWrite.vue'
import { useRoute } from 'vue-router'
import $ from 'jquery'
import { useStore } from 'vuex'
import { computed } from 'vue'

export default {
  name: 'UserProfileView',
  components: {
    ContentBase,
    UserProfileInfo,
    UserProfilePosts,
    UserProfileWrite,
  },
  setup() {
    const store = useStore();
    const route = useRoute();
    // 注意字母不要写错，应该是 userID 而不是 userId
    // 我这里写的乱七八糟的，分不清了
    const userId = parseInt(route.params.userID);
    const user = reactive({});  
    const posts = reactive({});
    $.ajax({
      url: 'https://app165.acapp.acwing.com.cn/myspace/getinfo/',
      type: 'GET',
      data: { 
        // 注意服务器的参数名为 user_id
        user_id: userId, // 登录的用户的用户ID
      },
      headers: { // 需要Jwt验证
        'Authorization': "Bearer " + store.state.user.access,
      },
      success(resp) {
        // console.log(resp);
        user.id = resp.id;
        user.username = resp.username;
        user.photo = resp.photo;
        // resp的参数应该与服务器一致
        user.followCount = resp.followerCount;
        user.is_followed = resp.is_followed;
      },
    });

    $.ajax({
        url: 'https://app165.acapp.acwing.com.cn/myspace/post/',
        type: 'GET',
        data: {
          user_id: userId, 
        },
        headers: { 
          'Authorization': 'Bearer ' + store.state.user.access,
        },
        success(resp) {
          console.log(resp);
          posts.count = resp.length;
          posts.posts = resp;
        }
    });


    // 这里的follow修改的是前端的内容
    const follow = () => {
      if(user.is_followed) return ;
      user.is_followed = true;
      user.followCount ++ ;
    }

    const unfollow = () => {
      if(!user.is_followed) return ;
      user.is_followed = false;
      user.followCount -- ;
    }

    const topic_post = (content) => {
      if(content === "")  return ;  // 不可以发空帖
      console.log("father", content);
      posts.count ++ ;
      posts.posts.push({
        // 这样设置ID不好，因为随着帖子的增删，id可能重复
        id: posts.count,
        userId: 1,
        content: content,
      })
    }

    const delete_post = delete_post_id => {
      // filter为true删掉，为false删掉
      posts.posts = posts.posts.filter((post) => {
          return post.id !== delete_post_id;
        } 
      );
      // posts.posts = posts.posts.filter(post => post.id !== delete_post_id);
      posts.count = posts.posts.length;
    }


    const is_me = computed(() => {
      return userId === store.state.user.id;
    });

    return {
      user: user, // 可以简写为user
      follow,
      unfollow,
      posts,
      topic_post,
      is_me,
      delete_post,
    }
  },
}
</script>



<style scoped></style>