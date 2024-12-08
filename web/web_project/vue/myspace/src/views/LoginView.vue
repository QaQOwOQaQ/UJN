<template>
  <ContentBase>
    <div class="row justify-content-md-center">
      <div class="col-3">
 <!-- .prevent用来阻止submit默认的行为(刷新网页) -->
    <!-- <form @submit.prevent="login"> -->
      <form @submit.prevent="login">
      <div class="mb-3">
        <label for="username" class="form-label">username</label>
        <input v-model="username" type="text" class="form-control" id="username">
      </div>
      <div class="mb-3">
        <!-- 通过v-model将input中的内容与ref绑定在一起 -->
        <label for="password" class="form-label">password</label>
        <input v-model="password" type="password" class="form-control" id="password">
      </div>
      <div class="error-message">{{ error_message }}</div>
      <button type="submit" class="btn btn-primary">log in</button>
    </form>
      </div>
    </div>

  </ContentBase>
</template>

<script>
// BUG:对于default export，引用时不能加上{}
import ContentBase from '../components/CoetentBase'
import { ref } from 'vue' 
import { useStore } from 'vuex'
import router from '@/router/index';  // @ 默认定位到src目录


export default {
  name: 'LoginView',
  components: {
    ContentBase,
  },
  setup() {
    const store = useStore();
    let username = ref('');
    let password = ref('');
    let error_message = ref('');

    const login = () => {
      error_message.value = "";
      // 通过dispatch调用action中的函数
      store.dispatch("login", {
        username: username.value,
        password: password.value, 
        success() { // 回调函数
          router.push({name: 'userlist'});  // 和navBar里面的跳转一样
        },
        error() {
          error_message.value = "username or password error!";
        }
      }); 
    }

    return {
      username,
      password,
      error_message,
      login,
    }
  },
}
</script>

<style scoped>
button {
  width: 100%;
}
.error-message {
  color: red;
  font-size: 12px;
}
</style>