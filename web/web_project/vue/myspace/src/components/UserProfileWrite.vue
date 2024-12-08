<template>
    <div class="card edit-field">
        <div class="card-body">
            <div>
            <label for="edit-field-post" class="form-label">edit a new topic</label>
            <textarea v-model="content" class="form-control" id="edit-field-post" rows="3"></textarea>
            <button type="button" @click="topic_post" class="btn btn-info btn-sm">post</button>
        </div>
        </div>
    </div>
</template>

<script>
import { ref } from 'vue'
import $ from 'jquery'
import { useStore } from 'vuex'

export default {
    name: 'UserProfileWrite',
    setup(props, context) {
        let content = ref('');
        const store = useStore();

        const topic_post = () => {
            $.ajax({
                url: 'https://app165.acapp.acwing.com.cn/myspace/post/',
                type: 'POST',
                data: {
                    content: content.value,
                },
                headers: {  // 需要Jwt验证
                    'Authorization': 'Bearer ' + store.state.user.access,
                },
                success(resp) {
                    if(resp.result == "success") {
                        console.log("son call");
                        context.emit('topic_post', content.value);
                        content.value = "";
                    }
                },
            })
        };

        return {
            content,
            topic_post,
        }
    }
}
</script>

<style>
.edit-field {
    margin-top: 10px;
}

button {
    margin-top: 5px;
}
</style>