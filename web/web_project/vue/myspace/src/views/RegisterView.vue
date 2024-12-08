<template>
  <ContentBase>
    <div class="row justify-content-md-center">
      <div class="col-3">
        <!-- .prevent用来阻止submit默认的行为(刷新网页) -->
        <!-- <form @submit.prevent="login"> -->
        <form @submit.prevent="register">
          <div class="mb-3">
            <label for="username" class="form-label">username</label>
            <input v-model="username" type="text" class="form-control" id="username">
          </div>
          <div class="mb-3">
            <!-- 通过v-model将input中的内容与ref绑定在一起 -->
            <label for="password" class="form-label">password</label>
            <input v-model="password" type="password" class="form-control" id="password">
          </div>
          <div class="mb-3">
            <label for="password-confirm" class="form-label">confirm password</label>
            <input v-model="password_confirm" type="password" class="form-control" id="password">
          </div>
          <div class="error-message">{{ error_message }}</div>
          <button type="submit" class="btn btn-primary">register</button>
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
import $ from 'jquery'


export default {
  name: 'RegisterView',
  components: {
    ContentBase,
  },
  setup() {
    const store = useStore();
    let username = ref('');
    let password = ref('');
    let password_confirm = ref('');
    let error_message = ref('');

    const register = () => {
      error_message.value = "";
      $.ajax({
        url: 'https://app165.acapp.acwing.com.cn/myspace/user/',
        type: 'POST',
        data: {
          username: username.value,
          password: password.value,
          password_confirm: password_confirm.value,
        },
        success(resp) {
          console.log(resp);
          // 如果注册成功就跳转到登录
          if (resp.result == "success") {
            store.dispatch("login", {
              username: username.value,
              password: password.value,
              success() { // 回调函数
                router.push({ name: 'userlist' });  // 和navBar里面的跳转一样
              },
              error() {
                error_message.value = "maybe system exception, please try again later.";
              }
            });
          }
          else {
            error_message.value = resp.result;
          }
        }
      })
    }

    return {
      username,
      password,
      password_confirm,
      error_message,
      register,
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